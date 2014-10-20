#!/bin/sh

SRC="Google3.cpp"

while true
do
    echo
    inotifywait -q -e close_write "$SRC"
    if [ -f "$SRC" ];
    then
	g++ -std=c++11 "$SRC" && ./a.out
    fi
    
    sleep 1
done

