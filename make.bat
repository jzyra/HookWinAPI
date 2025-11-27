@echo off

pushd "%~dp0"
mkdir output\obj
mkdir output\lib
gcc -c hook.c -o output\obj\hook.o
ar -r -s output\lib\libhook.a output\obj\hook.o
popd