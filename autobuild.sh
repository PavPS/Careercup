#!/bin/sh

SRC="JamesChen12.cpp"

while true
do
    echo
    ./a.out
    inotifywait -q -e close_write "$SRC"
    if [ -f "$SRC" ];
    then
	g++ -std=c++11 "$SRC"
    fi
    
    sleep 1
done

