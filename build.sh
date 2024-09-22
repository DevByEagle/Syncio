#!/bin/sh

# Check if a filename is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

FILENAME="$1"

# Check the file extension
case "$FILENAME" in
    *.c)
        echo "Compiling C file: $FILENAME"
        gcc "$FILENAME" -o Syncio.exe
        ;;
    *.cpp | *.c++)
        echo "Compiling C++ file: $FILENAME"
        g++ "$FILENAME" -o Syncio.exe
        ;;
    *)
        echo "Error: '$FILENAME' is not a C or C++ file."
        exit 1
        ;;
esac

echo "Build complete."