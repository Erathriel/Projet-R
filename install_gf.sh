#!/bin/bash

#Reset du dossier gf existant afin que le CMakeCache soit bien config...

#Dependence
sudo apt-get install libsdl2-dev libboost-filesystem-dev libboost-dev libfreetype6-dev zlib1g-dev cmake

#Suppression du dossier gf existant...
cd lib/
rep=gf
if [ -d $rep ]; then
			echo "$rep existe..."
			echo "rep : `pwd`"
			rm -rf gf			
fi

#Installation de gf...
git clone https://github.com/GamedevFramework/gf.git
cd gf
git submodule update --init
mkdir build
rep=build
if [ -d $rep ]; then
			echo "$rep existe..."
			cd $rep
			echo "rep : `pwd`"
			cmake ../ -DGF_BUILD_GAMES=ON -DGF_BUILD_TOOLS=ON
			make
			sudo make install
fi