#include <iostream> 
#include <string>

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
    std::string filePath = argv[1];
    size_t lastSlashPos = filePath.find_last_of('/');
    std::string fileName = filePath.substr(lastSlashPos + 1);

    std::cout<<"\n============ find keypoints: "<<fileName<<" ============"<<std::endl;
    Image img(argv[1]);
    img =  img.channels == 1 ? img : rgb_to_grayscale(img);

    std::vector<sift::Keypoint> kps = sift::find_keypoints_and_descriptors(img);
    Image result = sift::draw_keypoints(img, kps);
    result.save(fileName);

    std::cout << "Found " << kps.size() << " keypoints. Output image is saved as " << fileName <<"\n";
    return 0;
}
