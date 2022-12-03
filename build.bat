make clean
mkdir build
cd universal-otherapp && make && cp otherapp.bin ../otherapp.bin && cd ..
cp otherapp.bin build/otherapp.bin
make
cp uloader.3dsx f:/3ds
pause