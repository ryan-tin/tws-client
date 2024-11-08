#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "expected only one argument"
    echo "which test do you want to run?"
    exit 1
fi

echo "running test: $1"
ctest --test-dir build_tests -R $1
