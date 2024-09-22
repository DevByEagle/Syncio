@echo off
setlocal

rem Check if a filename is provided
if "%~1"=="" (
    echo Usage: %0 ^<filename^>
    exit /b 1
)

set FILENAME=%~1

rem Check the file extension
if /i "%~x1"==".c" (
    echo Compiling C file: %FILENAME%
    gcc "%FILENAME%" -o Syncio.exe
) else if /i "%~x1"==".cpp" (
    echo Compiling C++ file: %FILENAME%
    g++ "%FILENAME%" -o Syncio.exe
) else (
    echo Error: '%FILENAME%' is not a C or C++ file.
    exit /b 1
)

echo Build complete.
endlocal
