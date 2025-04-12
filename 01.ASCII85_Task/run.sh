#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: $0 [-e (encode) | -d (decode)] [--file <filename>]"
    exit 1
fi

mode="$1"
input=""
use_file=0
filename=""

# Check for --file option
if [ "$2" = "--file" ]; then
    if [ -z "$3" ]; then
        echo "Error: --file requires a filename"
        exit 1
    fi
    use_file=1
    filename="$3"
fi

if [ "$mode" != "-e" ] && [ "$mode" != "-d" ]; then
    echo "Error: Mode must be -e (encode) or -d (decode)"
    echo "Usage: $0 [-e (encode) | -d (decode)] [--file <filename>]"
    exit 1
fi

if [ "$use_file" = 1 ]; then
    if [ ! -f "$filename" ]; then
        echo "Error: File '$filename' not found"
        exit 1
    fi
    input="$filename"
else
    echo "Enter the string to $mode:"
    read -r input
fi

if [ -z "$input" ]; then
    echo "Error: Input string cannot be empty"
    exit 1
fi

./output "$mode" "$input" "$use_file"
