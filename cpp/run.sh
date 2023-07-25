#!/bin/bash

FILE_NAME=$1

if [[ -f "$FILE_NAME" ]]; then
    echo "FILE_NAME=$FILE_NAME"
    filename="${FILE_NAME%.*}"
    echo "filename=$filename"

    g++ $FILE_NAME -o $filename

    echo ""
    
    ./$filename
else
    echo "No cpp file was provided as an argument"
fi
