@echo off
setlocal

REM Define variables
set LIB_NAME=libsync.a
set SRC_DIR=src
set BUILD_DIR=build

REM Create build directory if it doesn't exist
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

REM Compile all source files in the src directory
for %%f in (%SRC_DIR%\*.c) do (
    echo Compiling %%f...
    gcc -c -o %BUILD_DIR%\%%~nf.o %%f
)

REM Archive object files into a static library
ar rcs %BUILD_DIR%\%LIB_NAME% %BUILD_DIR%\*.o

echo Build complete! Library created: %BUILD_DIR%\%LIB_NAME%

endlocal
pause
