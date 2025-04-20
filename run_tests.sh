#!/bin/bash

cmake --build build

cd build

ninja test

cd ..

