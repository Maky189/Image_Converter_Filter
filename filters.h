#ifndef FILTERS_H
#define FILTERS_H

struct rgbt {
    unsigned char rgbtBlue;
    unsigned char rgbtGreen;
    unsigned char rgbtRed;
};

void sepia(rgbt** image, int width, int height);
void grayscale(rgbt** image, int width, int height);
void blur(rgbt** image, int width, int height);
void edge(rgbt** image, int width, int height);

#endif // FILTERS_H
