#include "filters.h"
#include <math.h>

void sepia(rgbt** image, int width, int height) {
    // TODO: Implement sepia filter
    //sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    //sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue

    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
           float Red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
           float Green = round(0.349 * image[i][j].rgbtRed + 0.689 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
           float Blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

           if(Red > 255) Red = 255;
           if(Green > 255) Green = 255;
           if(Blue > 255) Blue = 255;

           image[i][j].rgbtRed = (int)Red;
           image[i][j].rgbtGreen = (int)Green;
           image[i][j].rgbtBlue = (int)Blue;
        }
    }
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

void reflect(rgbt** image, int width, int height)
{
    for (int i = 0; i < height; ++i)
    { 
        for (int j = 0, m = width - 1; j < width / 2; ++j, --m)
        {
            rgbt temp = image[i][j];
            image[i][j] = image[i][m];
            image[i][m] = temp;
        }
    }
    return;
}

void blur(rgbt** image, int width, int height) {
    // TODO: Implement blur filter
}

void edge(rgbt** image, int width, int height) {
    // TODO: Implement edge detection filter
}
