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
           int originalRed = image[i][j].rgbtRed;
           int originalGreen = image[i][j].rgbtGreen;
           int originalBlue = image[i][j].rgbtBlue;

           int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
           int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
           int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

           image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
           image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
           image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

void grayscale(rgbt** image, int width, int height) {
    // TODO: Implement grayscale filter
    for (int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

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
    // Dynamically allocate memory for the copy
    rgbt** copy = new rgbt*[height];
    for (int i = 0; i < height; ++i) {
        copy[i] = new rgbt[width];
        for (int j = 0; j < width; ++j) {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            float Red = 0, Green = 0, Blue = 0;
            int counter = 0;

            for (int li = -1; li <= 1; ++li) {
                for (int lj = -1; lj <= 1; ++lj) {
                    int ni = i + li;
                    int nj = j + lj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
                        Red += copy[ni][nj].rgbtRed;
                        Green += copy[ni][nj].rgbtGreen;
                        Blue += copy[ni][nj].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(Red / counter);
            image[i][j].rgbtGreen = round(Green / counter);
            image[i][j].rgbtBlue = round(Blue / counter);
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < height; ++i) {
        delete[] copy[i];
    }
    delete[] copy;
}

void edge(rgbt** image, int width, int height) {
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Dynamically allocate memory for the copy
    rgbt** copy = new rgbt*[height];
    for (int i = 0; i < height; ++i) {
        copy[i] = new rgbt[width];
        for (int j = 0; j < width; ++j) {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int redX = 0, greenX = 0, blueX = 0;
            int redY = 0, greenY = 0, blueY = 0;

            for (int li = -1; li <= 1; ++li) {
                for (int lj = -1; lj <= 1; ++lj) {
                    int ni = i + li;
                    int nj = j + lj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
                        redX += copy[ni][nj].rgbtRed * gx[li + 1][lj + 1];
                        greenX += copy[ni][nj].rgbtGreen * gx[li + 1][lj + 1];
                        blueX += copy[ni][nj].rgbtBlue * gx[li + 1][lj + 1];

                        redY += copy[ni][nj].rgbtRed * gy[li + 1][lj + 1];
                        greenY += copy[ni][nj].rgbtGreen * gy[li + 1][lj + 1];
                        blueY += copy[ni][nj].rgbtBlue * gy[li + 1][lj + 1];
                    }
                }
            }

            int red = round(sqrt(redX * redX + redY * redY));
            int green = round(sqrt(greenX * greenX + greenY * greenY));
            int blue = round(sqrt(blueX * blueX + blueY * blueY));

            image[i][j].rgbtRed = (red > 255) ? 255 : red;
            image[i][j].rgbtGreen = (green > 255) ? 255 : green;
            image[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < height; ++i) {
        delete[] copy[i];
    }
    delete[] copy;
}
