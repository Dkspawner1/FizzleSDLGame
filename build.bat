@echo off
echo Build started at %date% %time% > build_log.txt
echo SDL2_DIR is set to: %SDL2_DIR% >> build_log.txt

if not defined SDL2_DIR (
    echo SDL2_DIR is not set. Please set it to your SDL2 installation directory. >> build_log.txt
    exit /b 1
)

echo Cleaning up old files... >> build_log.txt
del /Q *.o game.exe 2>nul

echo Compiling source files... >> build_log.txt
gcc -c src\*.c -I"%SDL2_DIR%\include" -I"%SDL2_DIR%\include\SDL2" 2>> build_log.txt
if %errorlevel% neq 0 (
    echo Compilation failed. See build_log.txt for details. >> build_log.txt
    exit /b %errorlevel%
)

echo Linking... >> build_log.txt
gcc *.o -o game.exe -L"%SDL2_DIR%\lib" -lmingw32 -lSDL2main -lSDL2 -mwindows 2>> build_log.txt
if %errorlevel% neq 0 (
    echo Linking failed. See build_log.txt for details. >> build_log.txt
    exit /b %errorlevel%
)

del *.o

echo Build completed successfully at %date% %time% >> build_log.txt

type build_log.txt
