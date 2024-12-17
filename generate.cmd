mkdir build

call "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvars64.bat"

cmake -B build -S . -G "Visual Studio 17 2022"
rem cmake --build .

pause
