#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "uploads/example_video.mp4"; 
    std::ifstream file(filename, std::ios::binary);

    if (file.is_open()) {
        std::cout << "File opened successfully." << std::endl;

        char buffer[100];
        file.read(buffer, sizeof(buffer));

        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    return 0;
}
