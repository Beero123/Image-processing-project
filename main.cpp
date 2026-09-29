#include <iostream>
using namespace std;
#include "Image_Class.h"

void invertImage(Image &image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                image(i,j,k) = 255 - image(i,j,k);
            }

        }

    }
}
void adjustBrightness(Image &image, float percentage) {
    float shift = 255.0f * ( percentage / 100.0f );
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int newValue = image(i,j,k) + static_cast<int>(shift);
                if (newValue > 255) {
                    newValue = 255;
                }else if (newValue < 0) {
                    newValue = 0;
                }
                image(i,j,k) = static_cast<unsigned char>(newValue);
            }
        }
    }
}
int main() {
    string filename;
    cout << "Please enter an image name: ";
    cin >> filename;
    Image image(filename);

    int choice;

    cout << "Select a filter to apply:\n";
    cout << "1. invert Filter\n";
    cout << "2. Adjust Brightness (Lighten/Darken)\n";
    cin >> choice;
    if (choice == 1) {
        invertImage(image);
    }else if (choice == 2) {
        float percentage;
        cout << "Enter brightness percentage (+ for lighten, - for darken): ";
        cin >> percentage;
        adjustBrightness(image, percentage);
    }else {
        cout << "Invalid choice!\n";
    }


    cout << "pls enter an image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .gif: ";

    cin >> filename;
    image.saveImage(filename);
    return 0;
}