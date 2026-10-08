//====================================================================================
//======================================Part 2========================================
//Abrar Hussein Ibrahim Salih : 20253011 |||| filter: 1, 5, 9, 13
//Majd Abdalla Mohamed Omer : 20253013  ||| filter: 2, 6, 10, 14
//Rahaf Mohamed Elnaiem Mohamed : 20253040 |||| filter: 3, 7, 11, 15
//Widad Amir Abdalkhalig Abbas: 20253076 |||| filter: 4, 8, 12, 16
//section: S31, 32
//===================================================================================
//===================================================================================


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "Image_Class.h"
using namespace std;


void load_image(string& filename, Image& image);
void image_save(string& filename, Image& image);
void exit_editing();
void grayscale(Image& image);
void black_white(Image& image);
void invertImage(Image& image);
void image_flip(Image& image);
void rotate_image(Image& image);
void adjustBrightness(Image& image);
void resize_image(string& filename, Image& image);
void Infrared_filter(Image& image);


int main() {
    string filename;
    cout << "Please upload the image you would like to edit: ";
    getline(cin, filename);
    Image image(filename);
    
    bool cont_editing = true;
    int choice;

    while (cont_editing) {
        cout << "\nSelect the number of what you would like to do:\n"
             << " 0- Load a new image\n"
             << " 1- Convert to Grayscale\n"
             << " 2- Convert to Black and White\n"
             << " 3- Invert Image colors\n"
             << " 5- Flip Image\n"
             << " 6- Rotate Image\n"
             << " 7- Adjust Brightness\n"
             << " 8- Resize the image\n"
             << " 12- Apply Infrared filter\n"
             << " 19- Save the image\n"
             << " 20- Exit\n";
        
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 0:
                load_image(filename, image);
                break;
            case 1:
                grayscale(image);
                break;
            case 2:
                black_white(image);
                break;
            case 3:
                invertImage(image);
                break;
            case 5:
                image_flip(image);
                break;
            case 6:
                rotate_image(image);
                break;
            case 7: {
                adjustBrightness(image);
                break;
            }
            case 8:
                resize_image(filename, image);
                break;
            case 12:
                Infrared_filter(image);
                break;
            case 19:
                image_save(filename, image);
                break;
            case 20:
                exit_editing();
                cont_editing = false;
                break;
            default:
                cout << "Invalid number. Please pick again.\n";
        }
    }

    return 0;
}


// This function is used to ask the user to upload an image

void load_image(string& filename, Image& image){
    cout << "Please upload the image you would like to edit: ";
    getline(cin, filename);
    image.loadNewImage(filename);
    cout << "your image has been loaded successfully\n";

}


// This function is used to save an image

void image_save(string& filename, Image& image){
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    getline(cin, filename);
    image.saveImage(filename);

    cout << "Your image has been saved successfully.\n";
}


// This fucntion is used to exit the program

void exit_editing(){
    std::cout << "Exit Complete.\n";
    std::exit(0);
}




// These filters were created by Abrar




// These filters were created by Majd




//  These filters were created by Rahaf




// Filter 8 & 12 were created by Widad



