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

/*
* Filter 1 -Grayscale Conversion
* In grayscale images, there is no color information, only varying shades of gray from black to white.
*/

void grayscale(Image& image){
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


/*
* Filter 5 - image flip
* Flipping an image involves mirroring its contents horizontally or vertically.
*/

void image_flip(Image& image){
    cout << "1-Horizontal Flip" << endl;
    cout << "2-Vertical Flip" << endl;
    cout << "choose an option: ";
    Image flipImage(image.width, image.height);
    int option;
    cin >> option;
    if(option == 1)
    {
        for(int i = 0; i < image.height; i++)
        {
            for(int j = 0; j < image.width; j++)
            {
                for(int k = 0; k < image.channels; k++)
                {
                    flipImage(image.width - j - 1, i, k) = image(j, i, k);

                }
            }
        }
        image = flipImage;
        cout << "Image got flipped successfully." << endl;

    }else if(option == 2)
    {
        for(int i = 0; i < image.height; i++)
        {
            for(int j = 0; j < image.width; j++)
            {
                for(int k = 0; k < image.channels; k++)
                {
                    flipImage(j, image.height - i - 1, k) = image(j, i, k);

                }
            }
        }
        image = flipImage;
        cout << "Image got flipped successfully." << endl;
    }else{
        cout << "invalid input." << endl;
    }
}





// These filters were created by Majd

// filter 2 - This filter will turn an image into black and white after grayscaling it

void black_white(Image& image){
    grayscale(image);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (image(i, j, 0) > 128) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            } else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    cout << "Image turned into Black & White successfully." << endl;
}

/* 
* filter 6 - rotating an image
* This filter allows the user to rotate the image clockwise by 90º, 180º or 270º as the user chooses.
*/ 

void rotate_image(Image& image){
    cout << "Select the number of which rotation you would like to apply: \n";
	cout << "1. 90 degrees clockwise." << endl;
	cout << "2. 180 degrees clockwise." << endl;
	cout << "3. 270 degrees clockwise." << endl;
	int x;
	cin >> x;

	if (x == 1) {
		Image rotated(image.height, image.width);
		for (int i = 0; i < image.width; i++) {
			for (int j = 0; j < image.height; j++) {
				for (int k = 0; k < image.channels; k++) {
					rotated(image.height - 1 - j, i, k) = image(i, j, k);
				}
			}
		}
        cout << "Your image got rotated 90 degrees successfully." << endl;
		image = rotated;
	}
	else if (x == 2) {
		Image rotated(image.width, image.height);
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    rotated(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
                }
            }
        }
        cout << "Your image got rotated 180 degrees successfully." << endl;
        image = rotated;
	}
	else if (x == 3) {
		Image rotated(image.height, image.width);
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    rotated(j, image.width - 1 - i, k) = image(i, j, k);
                }
            }
        }
        cout << "Your image got rotated 270 degrees successfully." << endl;
        image = rotated;
	}
	else {
		cout << "Invalid input" << endl;
	}
}





//  These filters were created by Rahaf


/* transforms the colors of an image by reversing each pixel's RGB values. 
*This operation effectively produces a photographic negative effect, 
* where light areas become dark and vice versa
*/

void invertImage(Image &image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                image(i,j,k) = 255 - image(i,j,k);
            }

        }

    }
}

void adjustBrightness(Image &image) {
    float percentage;
        cout << "Enter brightness percentage (+ for lighten, - for darken): ";
        cin >> percentage;
        cin.ignore();
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



// Filter 8 & 12 were created by Widad

// This function is used to apply filter 8 to resize image

void resize_image(string& filename, Image& image){
    int new_width;
    cout << "Please enter new width: ";
    cin >> new_width;
    int new_height;
    cout << "Please enter new height: ";
    cin >> new_height;

    Image resized_image(new_width, new_height);

    int width, height;
    stbi_info(filename.c_str(), &width, &height, nullptr);

    float w = (width * 1.0f)/new_width;
    float h = (height * 1.0f)/new_height;

    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {

            for (int k = 0; k < 3; ++k) {
                resized_image(i, j, k) = image(std::floor(i*w), std::floor(j*h), k);
            }

        }
    }
    image = resized_image;
    cout << "your image got resized successfully.\n";
}


// This function is used to apply filter 12, Infrared radiation

void Infrared_filter(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++){
            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - image(i, j, 1);
            image(i, j, 2) = 255 - image(i, j, 2);

        }

    }
    cout << "Your Infrared filter got applied.\n";
}


