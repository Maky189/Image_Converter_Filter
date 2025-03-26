#include "filters.h"
#include <math.h>

void sepia(rgbt** image, int width, int height) {
    // TODO: Implement sepia filter
}

void grayscale(rgbt** image, int width, int height) {
    // TODO: Implement grayscale filter
    for (int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            int average = (int)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}

void blur(rgbt** image, int width, int height) {
    // TODO: Implement blur filter
}

void edge(rgbt** image, int width, int height) {
    // TODO: Implement edge detection filter
}
