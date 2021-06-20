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
    "${LOCAL_DIRS[@]}" \
    "$HOST":"$REMOTE_DIR/"

# Make on remote
# ssh -S "$SOCKET" "$HOST" "
#     cd '~/hls_project/bwa_hls'
#     make -j 8
# "

# Download reports
rsync \
    --rsh "ssh -S '$SOCKET'" \
    --archive --verbose --compress --update --progress --human-readable \
    "$HOST":"$REMOTE_DIR/Emulation-HW/binary_container_1.xclbin.link_summary" \
    :"$REMOTE_DIR/Emulation-HW/binary_container_1.xclbin.run_summary" \
    :"$REMOTE_DIR/Emulation-HW/binary_container_1.build/bwa_align.xo.compile_summary" \
    :"$REMOTE_DIR/Emulation-HW/xilinx_u50_gen3x16_xdma_201920_3-0-binary_container_1.wdb" \
    ./Emulation-HW/reports/