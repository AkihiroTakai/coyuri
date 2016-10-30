#!/bin/bash

while true
do
    kwrite ~/Documents/score.txt &
    dojp ./bin/coyuri
    pkill kwrite
    chmod 711 koryo.sh
done
