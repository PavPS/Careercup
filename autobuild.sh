#!/bin/sh

SRC=`ls -t *.cpp | head -n 1`

while true
do
    echo
    inotifywait -q -e close_write "$SRC"
    if [ -f "$SRC" ];
    then
	g++ -std=c++11 -Wall -Wextra -D_GLIBCXX_DEBUG "$SRC" && ./a.out
    fi
    
    sleep 1
done

