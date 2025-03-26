#ifndef FILTERS_H
#define FILTERS_H

void sepia(unsigned char* img, int width, int height, int channels);
void grayscale(unsigned char* img, int width, int height, int channels);
void blur(unsigned char* img, int width, int height, int channels);
void edge(unsigned char* img, int width, int height, int channels);

#endif // FILTERS_H
