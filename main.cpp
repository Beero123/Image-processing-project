<<<<<<< Updated upstream
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include <vector>

using namespace std;

void OilPaint(const unsigned char* inputImage, unsigned char* outputImage, int width, int height, int radius, int levels) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            
            int count[256] = {0};
            int rSum[256] = {0}, gSum[256] = {0}, bSum[256] = {0};

            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        int idx = (ny * width + nx) * 3;
                        int r = inputImage[idx];
                        int g = inputImage[idx + 1];
                        int b = inputImage[idx + 2];
                        
                        int intensity = (r * 299 + g * 587 + b * 114) / 1000;
                        int bin = (intensity * levels) / 256;
                        if (bin >= levels) bin = levels - 1; // Safety check

                        count[bin]++;
                        rSum[bin] += r;
                        gSum[bin] += g;
                        bSum[bin] += b;
                    }
                }
            }

            int maxCount = 0;
            int bestBin = 0;
            for (int i = 0; i < levels; i++) {
                if (count[i] > maxCount) {
                    maxCount = count[i];
                    bestBin = i;
                }
=======
#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

void image_save(string& filename, Image& image) {
    cout << "Enter image name with extension: ";
    getline(cin >> ws, filename);

    if (filename.find(".jpg") != string::npos ||
        filename.find(".png") != string::npos ||
        filename.find(".bmp") != string::npos ||
        filename.find(".jpeg") != string::npos)
    {
        image.saveImage(filename);
        cout << "Image saved successfully!\n";
    }
    else
    {
        cout << "Invalid extension!\n";
    }
}

void apply_invert_filter(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
>>>>>>> Stashed changes
            }

            int outIdx = (y * width + x) * 3;
            if (maxCount > 0) {
                outputImage[outIdx]     = rSum[bestBin] / maxCount;
                outputImage[outIdx + 1] = gSum[bestBin] / maxCount;
                outputImage[outIdx + 2] = bSum[bestBin] / maxCount;
            }
        }
    }
}

int main() {
<<<<<<< Updated upstream
    int width, height, channels;
    const char* filename = "luffy.jpg";
    unsigned char* imgData = stbi_load(filename, &width, &height, &channels, 3);

    if (!imgData) {
        cout << "Error: Failed to load image " << filename << endl;
        return -1;
    }

    cout << "Image loaded successfully! Width: " << width << ", Height: " << height << endl;
    
    int radius = 2;
    int levels = 8;

    cout << "Enter filter radius (recommended 2-5): ";
    cin >> radius;

    cout << "Enter color levels (recommended 8-16): ";
    cin >> levels;
    vector<unsigned char> outputImage(width * height * 3, 0);

    cout << "Applying Oil Paint filter..." << endl;
    OilPaint(imgData, outputImage.data(), width, height, radius, levels);
    stbi_image_free(imgData);
    
    const char* outputFilename = "oilPainted_output.png";
    stbi_write_png(outputFilename, width, height, 3, outputImage.data(), width * 3);

    cout << "Success! Saved output as " << outputFilename << endl;
=======
    string filename;
    cout << "Enter input image name: ";
    cin >> filename;

    Image image(filename);

    apply_invert_filter(image);

    image_save(filename, image);
>>>>>>> Stashed changes

    return 0;
}
