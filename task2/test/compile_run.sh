#!/bin/bash

echo "Starting test ..."

if g++ ../src/*.cpp $1 -O2 -Wall -o ./bin/"$1.exe" -I../include; then
    ./bin/"$1.exe"
else 
    echo "Test build failed!"
fi
    
