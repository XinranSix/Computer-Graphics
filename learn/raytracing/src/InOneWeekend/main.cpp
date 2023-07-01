/**
 * @file    :   main.cpp
 * @date    :   2023/07/01 10:56:10
 * @author  :   yaojie
 * @version :   1.0
 */

#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

// Image

const int image_width = 256;
const int image_height = 256;

// Render

std::ofstream ofs("image.ppm");

int main() {
    ofs << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i) / (image_width - 1),
                              double(j) / (image_height - 1), 0.25);
            write_color(ofs, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}