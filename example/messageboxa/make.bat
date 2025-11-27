@echo off

pushd "%~dp0"
mkdir output\dll
mkdir output\obj
gcc -I..\..\include -c main.c -o output\obj\messageboxa.o
gcc -shared -o output\dll\messageboxa.dll output\obj\messageboxa.o -L..\..\output\lib -lhook
popd
