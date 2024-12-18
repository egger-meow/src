#!/bin/bash
mkdir build/ && cd build && cmake .. && make
cd ../bin/
# ./find_keypoints ../imgs/small.png
# ./find_keypoints ../imgs/mid.jpg
# ./find_keypoints ../imgs/big.jpg
./match_features ../imgs/sclee.png ../imgs/sclee2.png