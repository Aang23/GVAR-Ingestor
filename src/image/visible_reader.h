#pragma once

#include <cstdint>
#define cimg_use_png
#define cimg_display 0
#include "CImg.h"

class VisibleReader
{
private:
    unsigned short *imageBuffer;
    unsigned short *imageLineBuffer;
    uint8_t byteBufShift[5];
    bool *goodLines;

public:
    int frames;
    VisibleReader();
    ~VisibleReader();
    void startNewFullDisk();
    void pushFrame(uint8_t *data, int block, int counter);
    cimg_library::CImg<unsigned short> getImage();
};