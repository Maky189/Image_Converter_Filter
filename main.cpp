#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include "filters.h" // Include the filters header
#include <iostream>
#include <vector>

int main() {
    int width, height, channels;

    // Load JPG image
    unsigned char* img = stbi_load("input.jpg", &width, &height, &channels, 3);
    if (!img) {
        std::cerr << "Failed to load image!" << std::endl;
        return 1;
    }

    std::cout << "Loaded image: " << width << "x" << height << " with " << channels << " channels" << std::endl;

    // Apply filters
    sepia(img, width, height, channels);
    grayscale(img, width, height, channels);
    blur(img, width, height, channels);
    edge(img, width, height, channels);

    // Convert back to JPG format
    stbi_write_jpg("output.jpg", width, height, 3, img, 100);

    // Free memory
    stbi_image_free(img);

    std::cout << "Image converted back to JPG!" << std::endl;
    return 0;
}
