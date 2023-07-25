#!/bin/bash

TARGET_PATH=$1

if [ -d "$TARGET_PATH" ]; then
    echo "TARGET_PATH=$TARGET_PATH"

    for f in "$TARGET_PATH"/*
    do
        if [[ $(basename $f) != *.cpp ]]; then
            echo "Removing '$(basename $f)'..."
            rm -rf $f
        fi
    done
else
    echo "TARGET_PATH={$TARGET_PATH} does not exists."
fi 