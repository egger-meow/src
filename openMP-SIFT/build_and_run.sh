#!/bin/bash
rm -r build/
rm -r bin/
mkdir build/ && cd build && cmake .. && make
cd ../bin/
srun ./find_keypoints ../imgs/small.png
srun ./find_keypoints ../imgs/mid.jpg
srun ./find_keypoints ../imgs/big.jpg