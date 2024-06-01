#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

struct RGB
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

enum class ColorLayer
{
    Red,
    Green,
    Blue
};

class Image
{
public:
    void load(const std::string& filename);
    int height() const;
    int width() const;
    void save_as(const std::string& filename);
    void add_watermark();
    void blurr();
    void extract_layer(ColorLayer color_layer);
    void filter();
    void flip_horizontally();
    void flip_vertically();
    void inflate();
    void negative();
    void rotate_clockwise_90();
    void sepia();
    void shrink();
    void to_grayscale();

private:
    std::vector<std::vector<RGB> > pixels;
    int my_width;
    int my_height;
    int color_depth;
    std::string magic;
    std::string filename;
};

#endif  // IMAGE_H
