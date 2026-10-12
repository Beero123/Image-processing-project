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
        filename.find(".jpeg") != string::npos ||
        filename.find(".hdr") != string::npos)
    {
        image.saveImage(filename);
        cout << "Image saved successfully!\n";
    }
    else
    {
        cout << "Invalid extension!\n";
    }
}

void grayscale(Image& image) {
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int avg;
            avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    cout << "Image is grayscaled" << endl;
}

int main() {
    string filename;
    cout << "Enter input image name: ";
    cin >> filename;

    Image image(filename);

    grayscale(image);

    image_save(filename, image);

    return 0;
} 