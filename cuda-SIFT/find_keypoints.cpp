#include <iostream> 
#include <string>
#include <chrono>

#include "image.hpp"
#include "sift.hpp"

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    if (argc != 2) {
        std::cerr << "Usage: ./find_keypoints input.jpg (or .png)\n";
        return 0;
    }
    Image img(argv[1]);
    img = img.channels == 1 ? img : rgb_to_grayscale(img);

    printf("w = %d, h = %d\n", img.width, img.height);

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<sift::Keypoint> kps = sift::find_keypoints_and_descriptors(img);
    Image result = sift::draw_keypoints(img, kps);
    result.save("result.jpg");
    std::cout << "Found " << kps.size() << " keypoints. Output image is saved as result.jpg\n";

    auto stop = std::chrono::high_resolution_clock::now();
 
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
 
    printf("Time taken by total function: %.3lf seconds\n", duration.count() / 1000.0);

    return 0;
}
