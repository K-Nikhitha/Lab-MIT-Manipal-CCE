#!/bin/sh
echo "Enter filename"
read filename
if [[ -d $filename ]]; then
    echo "$filename is a directory"
elif [[ -f $filename ]]; then
    echo "$filename is a file"
else
    echo "$filename is not valid"
    exit 1
fi
