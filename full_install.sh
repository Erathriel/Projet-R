#!/bin/bash

#Installation de gf...
./install_gf.sh > log.txt
#Reset du rep build...
rep=build
if [ -d $rep ]; then
			echo "$rep existe..."
			echo "rep : `pwd`"
			rm -rf build
			mkdir build
fi
#Rebuild de l'exe...
./install.sh >> log.txt