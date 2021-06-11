#!/bin/bash

LOCAL_DIRS=(src Emulation-SW Emulation-HW Hardware)
REMOTE_DIR='~/hls_project'

SOCKET=/tmp/ssh.sock
HOST=b07902143@hanstzou.csie.ntu.edu.tw
PORT=1600

# Kill connection on exit
# negative pid specifies process group
# trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

# Create connection if not exist
if [[ ! -f "$SOCKET" ]]; then
    (
        ssh -N \
            -o 'ControlMaster=yes' \
            -o "ControlPath=$SOCKET" \
            -p "$PORT" \
            "$HOST" &
    )
fi

# Upload only updated files
rsync \
    -e "ssh -S '$SOCKET'" \
    --archive --verbose --compress --update --progress --human-readable \
    "${LOCAL_DIRS[@]}" \
    "$HOST":"$REMOTE_DIR/"

# Make on remote
# ssh -S "$SOCKET" "$HOST" "
#     cd '~/hls_project/bwa_hls'
#     make -j 8
# "