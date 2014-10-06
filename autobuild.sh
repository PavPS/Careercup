#!/bin/sh

SRC="JamesChen8.cpp"

while true
do
    echo
    ./a.out
    echo
    inotifywait -e close_write "$SRC"
    if [ -f "$SRC" ];
    then
	g++ -std=c++11 "$SRC"
    fi
    
    sleep 1
done

