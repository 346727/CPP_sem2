#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC) throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto& line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!in) throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}

//funkcja 1
 void Image::save_as(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    std::ofstream out(filename, std::ios::binary);
    if (!out) throw std::invalid_argument("failed to open \"" + filename + "\" for writing");

    out << MAGIC << "\n";
    out << my_width << " " << my_height << "\n";
    out << color_depth << "\n";

    for (const auto& line : pixels)
    {
        out.write(reinterpret_cast<const char*>(line.data()), my_width * sizeof(RGB));
        if (!out) throw std::logic_error("failed to write binary pixel data to file " + filename);
    }
    std::cout << "Pomyúlnie zapisano \"" << filename << "\"\n";
}

//funkcja 2
void Image::add_watermark()
{
    int punktX = my_width - (my_width / 10);
    int punktY = my_height - (my_height / 10);
    int radius = static_cast<int>(std::sqrt((my_width - punktX) * (my_width - punktX) + (my_height - punktY) * (my_height - punktY)) / 7.0);

    RGB color = {0, 128, 0};

    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            int dx = x - punktX;
            int dy = y - punktY;
            if (std::sqrt(dx * dx + dy * dy) <= radius) {
                pixels[y][x] = color;
            }
        }
    }
}

//funckja 3
void Image::blurr()
{
    std::vector<std::vector<RGB>> original_pixels = pixels;

    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;
            for (int sy = -1; sy <= 1; ++sy) {
                for (int sx = -1; sx <= 1; ++sx) {
                    int ny = y + sy;
                    int nx = x + sx;
                    if (ny >= 0 && ny < my_height && nx >= 0 && nx < my_width) {
                        sum_red += original_pixels[ny][nx].red;
                        sum_green += original_pixels[ny][nx].green;
                        sum_blue += original_pixels[ny][nx].blue;
                        ++count;
                    }
                }
            }

            pixels[y][x].red = static_cast<unsigned char>(sum_red / count);
            pixels[y][x].green = static_cast<unsigned char>(sum_green / count);
            pixels[y][x].blue = static_cast<unsigned char>(sum_blue / count);
        }
    }
}

//funkcja 4
void Image::extract_layer(ColorLayer color_layer)
{
    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            if (color_layer == ColorLayer::Red) {
                pixels[y][x].green = 0;
                pixels[y][x].blue = 0;
            } else if (color_layer == ColorLayer::Green) {
                pixels[y][x].red = 0;
                pixels[y][x].blue = 0;
            } else if (color_layer == ColorLayer::Blue) {
                pixels[y][x].red = 0;
                pixels[y][x].green = 0;
            }
        }
    }
}

//funkcja 5
void Image::filter()
{
    for (int y = 0; y < my_height - 1; ++y) {
        for (int x = 0; x < my_width - 1; ++x) {
            int red2 = std::abs(pixels[y][x].red - pixels[y + 1][x + 1].red);
            int green2 = std::abs(pixels[y][x].green - pixels[y + 1][x + 1].green);
            int blue2 = std::abs(pixels[y][x].blue - pixels[y + 1][x + 1].blue);

            pixels[y][x].red = red2;
            pixels[y][x].green = green2;
            pixels[y][x].blue = blue2;
        }
    }
}

//funkcja 6
void Image::flip_horizontally()
{
    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width / 2; ++x) {
            RGB roboczy_h = pixels[y][x];
            pixels[y][x] = pixels[y][my_width - 1 - x];
            pixels[y][my_width - 1 - x] = roboczy_h;
        }
    }
}

//funkcja 7
void Image::flip_vertically()
{
    for (int y = 0; y < my_height / 2; ++y) {
        for (int x = 0; x < my_width; ++x) {
            RGB roboczy_v = pixels[y][x];
            pixels[y][x] = pixels[my_height - 1 - y][x];
            pixels[my_height - 1 - y][x] = roboczy_v;
        }
    }
}

//funkcja 8
void Image::inflate()
{
    int n_szerokosc = my_width * 2;
    int n_wysokosc = my_height * 2;
    std::vector<std::vector<RGB>> powiekszone(n_wysokosc, std::vector<RGB>(n_szerokosc));

    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            RGB nowy_pixel = pixels[y][x];
            powiekszone[2 * y][2 * x] = nowy_pixel;
            powiekszone[2 * y + 1][2 * x] = nowy_pixel;
            powiekszone[2 * y][2 * x + 1] = nowy_pixel;
            powiekszone[2 * y + 1][2 * x + 1] = nowy_pixel;
        }
    }
    pixels = powiekszone;
    my_width = n_szerokosc;
    my_height = n_wysokosc;
}

//funckja 9
void Image::negative()
{
    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            pixels[y][x].red = 255 - pixels[y][x].red;
            pixels[y][x].green = 255 - pixels[y][x].green;
            pixels[y][x].blue = 255 - pixels[y][x].blue;
        }
    }
}

//funckja 10
void Image::rotate_clockwise_90()
{
    std::vector<std::vector<RGB>> obrocone_pix(my_height, std::vector<RGB>(my_width));

    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            obrocone_pix[y][x] = pixels[my_width - 1 - x][y];
        }
    }
    pixels = obrocone_pix;
    my_width = obrocone_pix[0].size();
    my_height = obrocone_pix[1].size();
}

//funkcja 11
void Image::sepia()
{
    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            RGB& pixel = pixels[y][x];

            int gray = (pixel.red + pixel.green + pixel.blue) / 3;

            int red = gray * 162 / 255;
            int green = gray * 128 / 255;
            int blue = gray * 101 / 255;

            pixel.red = (red > 255) ? 255 : red;
            pixel.green = (green > 255) ? 255 : green;
            pixel.blue = (blue > 255) ? 255 : blue;
        }
    }
}


//funkcja 12
void Image::shrink()
{
    int n_width = my_width / 2;
    int n_height = my_height / 2;
    std::vector<std::vector<RGB>> zmniejszone(n_height, std::vector<RGB>(n_width));

    for (int y = 0; y < n_height; ++y) {
        for (int x = 0; x < n_width; ++x) {
            int y1 = 2 * y;
            int x1 = 2 * x;
            int y2 = y1 + 1;
            int x2 = x1 + 1;

            zmniejszone[y][x].red = (pixels[y1][x1].red + pixels[y1][x2].red + pixels[y2][x1].red + pixels[y2][x2].red) / 4;
            zmniejszone[y][x].green = (pixels[y1][x1].green + pixels[y1][x2].green + pixels[y2][x1].green + pixels[y2][x2].green) / 4;
            zmniejszone[y][x].blue = (pixels[y1][x1].blue + pixels[y1][x2].blue + pixels[y2][x1].blue + pixels[y2][x2].blue) / 4;
        }
    }

    pixels = zmniejszone;
    my_width = n_width;
    my_height = n_height;
}

//funckja 13
void Image::to_grayscale()
{
    for (int y = 0; y < my_height; ++y) {
        for (int x = 0; x < my_width; ++x) {
            RGB& pixel = pixels[y][x];

            unsigned char gray = static_cast<unsigned char>((pixel.red + pixel.green + pixel.blue) / 3);

            pixel.red = gray;
            pixel.green = gray;
            pixel.blue = gray;
        }
    }
}

//funkcja 14
int Image::height() const
{
    return my_height;
}

//funkcja 15
int Image::width() const
{
    return my_width;
}

