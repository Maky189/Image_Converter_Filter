#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include "filters.h" // Include the filters header
#include <iostream>
#include <vector>

int main() {
    int width, height, channels;
    unsigned char* img = nullptr;

    std::cout << "Image Processing" << std::endl;
    std::cout << "---------------" << std::endl;

    while (true) {
        std::cout << "Provide the image you want to process (JPG file): " << std::endl;
        char input[100];
        std::cin >> input;

        // Attempt to load the image
        img = stbi_load(input, &width, &height, &channels, 3);
        if (img) {
            std::cout << "Loaded image: " << width << "x" << height << " with " << channels << " channels" << std::endl;
            break;
        } else {
            std::cerr << "Failed to load image! Please check the file path and try again." << std::endl;
        }
    }

    // Convert raw image data to Matrix object
    rgbt** image = new rgbt*[height];
    for (int i = 0; i < height; ++i) {
        image[i] = new rgbt[width];
        for (int j = 0; j < width; ++j) {
            int idx = (i * width + j) * 3;
            image[i][j].rgbtBlue = img[idx];
            image[i][j].rgbtGreen = img[idx + 1];
            image[i][j].rgbtRed = img[idx + 2];
        }
    }

    std::cout << "Choose the filter you want to apply" << std::endl;
    std::cout << "1. Sepia" << std::endl;
    std::cout << "2. Grayscale" << std::endl;
    std::cout << "3. Blur" << std::endl;
    std::cout << "4. Edge Detection" << std::endl;
    std::cout << "5. Reflect Image" << std::endl;

    int choice;
    std::cin >> choice;
    // Apply filters
    switch (choice) {
    case 1:
        sepia(image, width, height);
        break;
    case 2:
        grayscale(image, width, height);
        break;
    case 3:
        blur(image, width, height);
        break;
    case 4:
        edge(image, width, height);
        break;
    case 5:
        reflect(image, width, height);
        break;

    default:
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }

    // Convert Matrix object back to raw image data
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int idx = (i * width + j) * 3;
            img[idx] = image[i][j].rgbtBlue;
            img[idx + 1] = image[i][j].rgbtGreen;
            img[idx + 2] = image[i][j].rgbtRed;
        }
        delete[] image[i];
    }
    delete[] image;

    // Convert back to JPG format
    stbi_write_jpg("output.jpg", width, height, 3, img, 100);

    // Free memory
    stbi_image_free(img);

    std::cout << "Image processed!" << std::endl;
    return 0;
}
