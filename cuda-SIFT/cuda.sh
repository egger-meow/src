# CUDA
nvcc -o my_app -gencode=arch=compute_86,code=sm_86 -Xcompiler '-fPIC' -g -O3 find_keypoints.cpp image.cu sift.cpp -diag-suppress 550