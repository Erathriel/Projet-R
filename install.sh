#!/bin/bash

#compilation et install sous linux avec exec dans bin avec les log de la compil dans build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=~/Bureau/Projet-R > log.txt
make VERBOSE=true install >> log.txt