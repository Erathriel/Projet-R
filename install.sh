#!/bin/bash

#compilation et install sous linux avec exec dans bin
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=~/Desktop/Projet-R > log.txt
make VERBOSE=true install >> log.txt