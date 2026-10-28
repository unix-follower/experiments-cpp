#!/usr/bin/env bash

set -ex

build() {
    rm -rf build

    vcpkg install
    cmake --preset=vcpkg
    cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
    cmake --build --preset=vcpkg
    ctest --preset=vcpkg
}

rebuild() {
    cmake --preset=vcpkg
    cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
    cmake --build --preset=vcpkg
}

case "$1" in
    build)
        build
        ;;
    rebuild)
        rebuild
        ;;
    *)
        echo "Usage: $0 {function name}"
        exit 1
        ;;
esac
