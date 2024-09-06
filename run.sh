#!/usr/bin/env fish

if not make
    echo "Build failed"
    exit 1
end

if not ./game.exe
    echo "Game exited with an error"
end

make clean
