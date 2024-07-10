@echo off

cd ..

cd QbitLite

call git submodule update --init

cd Scripts

call CreateSolution.bat

cd ..

call cmake -S .

pause