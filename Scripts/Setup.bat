@echo off

cd ..

cd QbitLite/Scripts

call Setup.bat

call CreateSolution.bat

cd ../..

call cmake .

pause