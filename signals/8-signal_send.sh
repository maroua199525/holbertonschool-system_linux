#!/usr/bin/env sh

if [ $# -ne 1 ] || ! echo "$1" | grep -Eq '^-?[0-9]+$'; then
    echo "Usage: $0 <pid>"
    exit 1
fi

kill -s QUIT "$1"
