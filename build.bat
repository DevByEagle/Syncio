@echo off
set CC=cc
set CFLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -g

set SRC_DIR=src
set BUILD_DIR=build
for /R %SRC_DIR% %%i in (*.c) do (set SRC_FILES=!SRC_FILES! %%i)
for %%i in (%SRC_DIR%\*.c) do (set SRC_FILES=!SRC_FILES! %%i)

set HDR_DIR=include
for /R %HDR_DIR% %%i in (*.h) do (set HDR_FILES=!HDR_FILES! %%i)
for %%i in (%HDR_DIR%\*.h) do (set HDR_FILES=!HDR_FILES! %%i)

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

rem Build object files
for %%i in (%SRC_FILES%) do (
    set OBJ_FILE=%BUILD_DIR%\%%~ni.o
    echo (COMP) %%~ni.o
    %CC% %CFLAGS% -I%HDR_DIR% -c %%i -o !OBJ_FILE!
)

rem Link to create the main executable
echo (LINK) %BUILD_DIR%\main
%CC% %CFLAGS% -o %BUILD_DIR%\main %BUILD_DIR%\*.o

rem Copy the final executable
copy %BUILD_DIR%\main syncio
echo (DONE) all

rem Clean target
:clean
echo (CLEAN)
rd /s /q %BUILD_DIR%
del syncio
