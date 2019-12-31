#!/bin/bash

# cree les rep de base du projet et des fichiers 
#pour qu'ils soient non vide

tabRep=('src' 'bin' 'build' 'doc' 'include' 'lib' 'tests')
tabFile=('main.cpp' 'initBin.txt' 'initBuild.txt' 'initDoc.txt' 'initInclude.txt' 'initLib.txt' 'initTest.txt')

function createRepFile(){
	for (( i = 0; i < 7; i++ )); do
		rep=${tabRep[i]}
		file=${tabFile[i]}

		if [ -d $rep ]; then
			echo "$rep existe..."
			cd $rep
			echo "rep : `pwd`"
			if ! [ -e $file ]; then
				echo "$file inexistant..."
				echo "creation de $file..."
				touch $file
				echo "$file creer"
			else
				echo "$file deja creer"
			fi
			cd ..
			echo "rep : `pwd`"
		else
			echo "$rep inexistant..."
			echo "creation de $rep..."
			mkdir $rep
			echo "$rep creer"
			cd $rep
			echo "rep : `pwd`"
			echo "$file inexistant..."
			echo "creation de $file..."
			touch $file
			echo "$file creer"
			cd ..
			echo "rep : `pwd`"
		fi
	done
	echo "creation des fichiers et repertoires terminee..."
}

# script

createRepFile