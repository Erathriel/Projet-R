#!/bin/bash

cd lib/
rep=gf
if [ -d $rep ]; then
			echo "$rep existe..."
			echo "rep : `pwd`"
			rm -rf gf			
fi
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