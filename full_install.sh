./install_gf.sh
rep=build
if [ -d $rep ]; then
			echo "$rep existe..."
			echo "rep : `pwd`"
			rm -rf build
			mkdir build
fi
./install.sh