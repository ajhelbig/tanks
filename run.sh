#!/usr/bin/env bash

clear

echo "----------CHECKOUT----------"

echo "----------CONFIG----------"

cd build
cmake ..

echo "----------CONFIG----------"


echo "----------BUILD----------"

cmake --build .

echo "----------BUILD----------"


echo "----------RUN----------"

cd src
./ProjectName
#valgrind ./ProjectName

echo "----------RUN----------"
