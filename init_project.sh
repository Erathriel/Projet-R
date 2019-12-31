#!/bin/bash

# cree les rep de base du projet et des fichiers 
#pour qu'ils soient non vide

tabRep=('src' 'bin' 'build' 'doc' 'include' 'lib' 'tests')
tabFile=('main.cpp' 'initBin' 'initBuild' 'initDoc' 'initInclude' 'initLib' 'initTest')

function createRepFile(){
	rep=src
	file=main.cpp

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

	rep=bin
	file=initBin.txt

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

	rep=build
	file=initBuild.txt

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

	rep=doc
	file=initDoc.txt

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

	rep=include
	file=initInclude.txt

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

	rep=lib
	file=initLib.txt

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

	rep=tests
	file=initTest.txt

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
	echo "creation des fichiers et repertoires terminee..."
}

# script

createRepFile