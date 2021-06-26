#!/bin/bash

LOCAL_DIRS=(src Emulation-SW Emulation-HW Hardware)
REMOTE_DIR='~/hls_project'

SOCKET=/tmp/ssh.sock
HOST=b07902143@hanstzou.csie.ntu.edu.tw
PORT=1600

# Kill connection on exit
# negative pid specifies process group
# trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

while [[ "$1" ]]; do
    case $1 in
        -dl)
            opt_dl=1
            ;;
    esac

    shift
done

# Create connection if not exist
if [[ ! -e "$SOCKET" ]]; then
    echo "Creating connection..."
    (
        ssh -N \
            -o 'ControlMaster=yes' \
            -o "ControlPath=$SOCKET" \
            -p "$PORT" \
            "$HOST" &
    )
    sleep 5
fi

# Upload only updated files
rsync \
    --rsh "ssh -S '$SOCKET'" \
    --archive --verbose --compress --update --progress --human-readable \
    --exclude '**/reports' \
    --exclude '**/build*' \
    "${LOCAL_DIRS[@]}" \
    "$HOST":"$REMOTE_DIR/"

# Make on remote
# ssh -S "$SOCKET" "$HOST" "
#     cd '~/hls_project/bwa_hls'
#     make -j 8
# "

# Download reports
if (( opt_dl )); then
    rsync \
        --rsh "ssh -S '$SOCKET'" \
        --archive --verbose --compress --update --progress --human-readable \
        --exclude '**/binary_container_1.xclbin' \
        --exclude '**/binary_container_1.build/link' \
        --exclude '**/binary_container_1.build/bwa_align/bwa_align/bwa_align/solution' \
        --exclude '**/.run' \
        "$HOST":"$REMOTE_DIR/Emulation-HW/" \
        ./Emulation-HW/build
fi