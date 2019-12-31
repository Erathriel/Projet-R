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
				echo "$file creer..."
			else
				echo "$file deja creer..."
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
			echo "$file creer..."
			cd ..
			echo "rep : `pwd`"
		fi
	done
	file=install.sh
	if ! [ -e $file ]; then
				echo "$file inexistant..."
				echo "$file de install.sh..."
				touch $file
				echo "$file creer..."
	else
		echo "$file deja creer..."
	fi
	file=CMakeLists.txt
	if ! [ -e $file ]; then
				echo "$file inexistant..."
				echo "$file de install.sh..."
				touch $file
				echo "$file creer..."
	else
		echo "$file deja creer..."
	fi
	echo "creation des fichiers et repertoires terminee..."
}

function initMainCPP(){
	cd ${tabRep[0]}
	file=${tabFile[0]}
	if ! [ -e $file ]; then
				echo "$file inexistant..."
				echo "$file de install.sh..."
				touch $file
				echo "$file creer..."
	else
		echo "$file deja creer..."
	fi
	if ! [ -s $file ]; then
		echo -e "#include <iostream>\n\nint main(int argc, char * argv[]) {\n	std::cout << \"! dlrow olleH\" << std::endl;\n}" > $file
		echo "$file init..."
	else
		echo "$file deja init..."
	fi
	cd ..
}

function initCMakeLists(){
	file=CMakeLists.txt
	if ! [ -e $file ]; then
				echo "$file inexistant..."
				echo "$file de install.sh..."
				touch $file
				echo "$file creer..."
	else
		echo "$file deja creer..."
	fi
	if ! [ -s $file ]; then
		echo -e "cmake_minimum_required( VERSION 2.8 )\nset(CMAKE_BUILD_TYPE Release)\nproject (Projet-R)\nadd_subdirectory(src)" > $file
		echo "$file init..."
	else
		echo "$file deja init..."
	fi
}

function initInstall(){
	file=install.sh
	if ! [ -e $file ]; then
				echo "$file inexistant..."
				echo "$file de install.sh..."
				touch $file
				echo "$file creer..."
	else
		echo "$file deja creer..."
	fi
	if ! [ -s $file ]; then
		echo -e "cmake_minimum_required( VERSION 2.8 )\nset(CMAKE_BUILD_TYPE Release)\nproject (Projet-R)\nadd_subdirectory(src)" > $file
		echo "$file init..."
	else
		echo "$file deja init..."
	fi
}

# script

createRepFile
initMainCPP
initCMakeLists
initInstall