#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

int clampColor(float value) {
    if (value < 0.0) return 0;
    if (value > 255.0) return 255;
    return static_cast<int>(value);
}

void cropImage(Image &image) {
    cout<<"original Dimensions: "<< image.width << "x" << image.height <<endl;
    int x,y,width,height;
    cout<<"Enter starting point(x, y): "<<endl;
    cin>>x>>y;
    cout<<"Enter crop dimensions(width, height): "<<endl;
    cin>>width>>height;

    if (x < 0 || y < 0 || x >= image.width || y >= image.height){
        cout <<"Error:starting point (x, y)is out of image bounds!\n";

        return;
    }
    if (width <= 0 || height <= 0 ||(x + width) > image.width || (y + height) > image.height) {
        cout <<"Error:crop region exceeds image dimensions!\n";
        return;
    }
    Image croppedImage(width,height);

    for (int i = 0; i < croppedImage.width; i++) {
        for (int j = 0; j < croppedImage.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                croppedImage(i, j, k) = image(x + i, y + j, k);
            }

        }
    }
    string newImage;
    cout<<"Enter new image name: "<<endl;
    cin>>newImage;

    croppedImage.saveImage(newImage);

}
void purpleTint(Image &image) {
    float boostR,reduceG,boostB;
    cout<<"Enter boost R & reduce G & boost B: "<<endl;
    cin>>boostR>>reduceG>>boostB;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            float new_R = static_cast<float>(image(i, j, 0)) * boostR;
            float new_G = static_cast<float>(image(i, j, 1))* reduceG;
            float new_B = static_cast<float>(image(i, j, 2)) * boostB;

            image(i, j, 0) = clampColor(new_R);
            image(i, j, 1) = clampColor(new_G);
            image(i, j, 2) = clampColor(new_B);
        }
    }

}
int main() {
    string filename;
    cout<<"Enter filename: ";
    cin>>filename;
    Image image;
    image.loadNewImage(filename);

    int choice;
    cout<<"__Menu__\n";
    cout<<"1. crop image\n";
    cout<<"2. purple image\n";
    cout<<"Enter choice: "<<endl;
    cin>>choice;

    switch(choice) {
        case 1:
            cropImage(image);
            break;
        case 2:
            purpleTint(image);
            break;
        default:
            cout<<"Invalid choice!\n";
            return 0;
    }
    image.saveImage(filename+"output.jpg");
    return 0;
}