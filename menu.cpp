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

int clampColor(float value) {
    if (value < 0.0) return 0;
    if (value > 255.0) return 255;
    return static_cast<int>(value);
}

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
void Detect_Image_edges(string& filename, Image& image);
void cropImage(Image& image);
void Apply_TV_Effect(string& filename, Image& image);
void Infrared_filter(Image& image);
void purpleTint(Image& image);
void merge_image(Image& image1,Image& image2);
void Sunlight(Image& image);



int main() {
    string filename;
    cout << "Please upload the image you would like to edit: ";
    getline(cin, filename);
    Image image(filename);

    Image old_image;
    old_image = image;

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
            << " 10_ Detect_Image_edges\n"
            << " 11_ crop the image\n"
            << " 12- Apply Infrared filter\n"
            << " 14_ Apply_TV_Effect\n"
            << " 15_ apply purple-tint\n"
            << " 16_ apply Merge images\n"
            << " 17_ apply Sunlight\n"
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
        case :
            Detect_Image_edges(filename, image);
            break;
        case 11:
            cropImage(image);
            break;
        case 12:
            Infrared_filter(image);
            break;
        case 14:
            Apply_TV_Effect(filename, image);
            break;
        case 15:
            purpleTint(image);
   break;
        case 16 :
            merge images (image);
    break; 
        case 17 :
            Sunlight(Image& image)
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

void load_image(string& filename, Image& image) {
    cout << "Please upload the image you would like to edit: ";
    cin.ignore();
    getline(cin, filename);
    image.loadNewImage(filename);
    cout << "your image has been loaded successfully\n";

}


// This function is used to save an image

void image_save(string& filename, Image& image) {

    cout << "Pls enter image name to store new image\n";
    getline(cin >> ws, filename);
    
    image.saveImage(filename);

    cout << "Your image has been saved successfully.\n";
}

// This function removes the latest filter the user has applied from the picture

void unapply_filter (Image& image, Image old_image){
        image = old_image;
        cout << "your latest filter has been removed successfully";

    }


// This fucntion is used to exit the program

void exit_editing() {
    std::cout << "Exit Complete.\n";
    std::exit(0);
}
// These filters were created by Abrar

/*
* Filter 1 -Grayscale Conversion
* In grayscale images, there is no color information, only varying shades of gray from black to white.
*/

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


/*
* Filter 5 - image flip
* Flipping an image involves mirroring its contents horizontally or vertically.
*/

void image_flip(Image& image) {
    cout << "1-Horizontal Flip" << endl;
    cout << "2-Vertical Flip" << endl;
    cout << "choose an option: ";
    Image flipImage(image.width, image.height);
    int option;
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < image.height; i++)
        {
            for (int j = 0; j < image.width; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    flipImage(image.width - j - 1, i, k) = image(j, i, k);

                }
            }
        }
        image = flipImage;
        cout << "Image got flipped successfully." << endl;

    }
    else if (option == 2)
    {
        for (int i = 0; i < image.height; i++)
        {
            for (int j = 0; j < image.width; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    flipImage(j, image.height - i - 1, k) = image(j, i, k);

                }
            }
        }
        image = flipImage;
        cout << "Image got flipped successfully." << endl;
    }
    else {
        cout << "invalid input." << endl;
    }
}





// These filters were created by Majd

// filter 2 - This filter will turn an image into black and white after grayscaling it

void black_white(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (image(i, j, 0) > 128) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
            else {
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

void rotate_image(Image& image) {
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

// filter 10 - This filter is used to detect the edges of an image using the Sobel operator. The user can choose to apply either white or black edges.
void Detect_Image_edges(string& filename, Image& image) {
    int x;
    cout << "select the number of which colors you would like to apply" << endl << "1. for white edges " << endl << "2. for black edges " << endl;
    cin >> x;
    Image edge(image.width, image.height);
    for (int i = 1;i < image.width - 1;i++) {
        for (int j = 1;j < image.height - 1;j++) {
            int p1 = (image(i - 1, j - 1, 0) + image(i - 1, j - 1, 1) + image(i - 1, j - 1, 2)) / 3;
            int p2 = (image(i, j - 1, 0) + image(i, j - 1, 1) + image(i, j - 1, 2)) / 3;
            int p3 = (image(i + 1, j - 1, 0) + image(i + 1, j - 1, 1) + image(i + 1, j - 1, 2)) / 3;
            int p4 = (image(i - 1, j, 0) + image(i - 1, j, 1) + image(i - 1, j, 2)) / 3;
            int p5 = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            int p6 = (image(i + 1, j, 0) + image(i + 1, j, 1) + image(i + 1, j, 2)) / 3;
            int p7 = (image(i - 1, j + 1, 0) + image(i - 1, j + 1, 1) + image(i - 1, j + 1, 2)) / 3;
            int p8 = (image(i, j + 1, 0) + image(i, j + 1, 1) + image(i, j + 1, 2)) / 3;
            int p9 = (image(i + 1, j + 1, 0) + image(i + 1, j + 1, 1) + image(i + 1, j + 1, 2)) / 3;
            //horizontal and vertical changes
            //horizontal change as HChange
            //vertical change as VChange
            int HChange = -p1 + p3 - 2 * p4 + 2 * p6 - p7 + p9;
            int VChange = p1 + 2 * p2 + p3 + -p7 + -2 * p8 + -p9;
            double threshold = sqrt(HChange * HChange + VChange * VChange);
            if (x == 1)
                if (threshold > 100) {
                    edge(i, j, 0) = 255;
                    edge(i, j, 1) = 255;
                    edge(i, j, 2) = 255;
                }
                else {
                    edge(i, j, 0) = 0;
                    edge(i, j, 1) = 0;
                    edge(i, j, 2) = 0;
                }
            else if (x == 2) {
                if (threshold > 100) {
                    edge(i, j, 0) = 0;
                    edge(i, j, 1) = 0;
                    edge(i, j, 2) = 0;
                }
                else {
                    edge(i, j, 0) = 255;
                    edge(i, j, 1) = 255;
                    edge(i, j, 2) = 255;
                }
            }
        }
    }
    image = edge;
    if (x == 1) {
        cout << "White edges applied successfully." << endl;
    }
    else if (x == 2) {
        cout << "Black edges applied successfully." << endl;
    }
    else {
        cout << "Invalid input. Please enter a valid number." << endl;
    }
}
// filter 14 - This filter is used to apply a TV effect to an image. The user can choose to apply a horizontal, vertical, or both effects.
void Apply_TV_Effect(string& filename, Image& image) {
    int x;
    cout << "Enter the number for the effect you want to be apply: " << endl << "1. for horizontal effect " << endl << "2. for vertical effect" << endl << "3. for both effects " << endl;
    cin >> x;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                if (x == 1 && j % 2 == 0) {
                    image(i, j, k) = image(i, j, k) / 2;
                }
                else if (x == 2 && i % 2 == 0) {
                    image(i, j, k) = image(i, j, k) / 2;
                }
                else if (x == 3 && (j % 2 == 0 || i % 2 == 0)) {
                    image(i, j, k) = image(i, j, k) / 2;
                }
            }
        }
    }
    if (x == 1) {
        cout << "Horizontal effect applied successfully." << endl;
    }
    else if (x == 2) {
        cout << "Vertical effect applied successfully." << endl;
    }
    else if (x == 3) {
        cout << "Both effects applied successfully." << endl;
    }
    else {
        cout << "Invalid input. Please enter a valid number." << endl;
    }
}





//  These filters 3, 7, 11 & 15 were created by Rahaf


/* transforms the colors of an image by reversing each pixel's RGB values.
*This operation effectively produces a photographic negative effect,
* where light areas become dark and vice versa
*/

void invertImage(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = 255 - image(i, j, k);
            }

        }

    }
}

void adjustBrightness(Image& image) {
    float percentage;
    cout << "Enter brightness percentage (+ for lighten, - for darken): ";
    cin >> percentage;
    cin.ignore();
    float shift = 255.0f * (percentage / 100.0f);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int newValue = image(i, j, k) + static_cast<int>(shift);
                if (newValue > 255) {
                    newValue = 255;
                }
                else if (newValue < 0) {
                    newValue = 0;
                }
                image(i, j, k) = static_cast<unsigned char>(newValue);
            }
        }
    }
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


// Filter 8 & 12 were created by Widad

// This function is used to apply filter 8 to resize image

void resize_image(string& filename, Image& image) {
    int new_width;
    cout << "Please enter new width: ";
    cin >> new_width;
    int new_height;
    cout << "Please enter new height: ";
    cin >> new_height;

    Image resized_image(new_width, new_height);

    int width, height;
    stbi_info(filename.c_str(), &width, &height, nullptr);

    float w = (width * 1.0f) / new_width;
    float h = (height * 1.0f) / new_height;

    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {

            for (int k = 0; k < 3; ++k) {
                resized_image(i, j, k) = image(std::floor(i * w), std::floor(j * h), k);
            }

        }
    }
    image = resized_image;
    cout << "your image got resized successfully.\n";
}

// This function is used to apply filter 12, Infrared radiation

void Infrared_filter(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - image(i, j, 1);
            image(i, j, 2) = 255 - image(i, j, 2);

        }

    }
    cout << "Your Infrared filter got applied.\n";
    
    // This function is used to apply fliter 9, Merge images
    
    void merge_image(Image& image1, Image& image2))
    int width1 = image1.width;
    int height1 = image1.height;
    int width2 = image2.width;
    int height2 = image2.height;
    // If the two images have the same size
    if (width1 == width2 && height1 == height2)
    {
        Image mergedImage(width1, height1);
        for (int i = 0; i < height1; i++)
        {
            for (int j = 0; j < width1; j++)
            {
                for (int k = 0; k < image1.channels; k++)
                {
                    mergedImage(j, i, k) =
                        (image1(j, i, k) + image2(j, i, k)) / 2;
                }
            }
        }
        mergedImage.save("merged_image.jpg");
    }
    // If the images have different sizes
    else
    {
        cout << "Images have different sizes." << endl;
        cout << "1 - Resize both images to the same size" << endl;
        cout << "2 - Merge the common area" << endl;
        int option;
        cin >> option;
        // Option 1: Resize
        if (option == 1)
        {
            int newWidth = max(width1, width2);
            int newHeight = max(height1, height2);
            Image resizedImage1(newWidth, newHeight);
            Image resizedImage2(newWidth, newHeight);
            // Resize image 1
            for (int i = 0; i < newHeight; i++)
            {
                for (int j = 0; j < newWidth; j++)
                {
                    for (int k = 0; k < image1.channels; k++)
                    {
                        int x = j * width1 / newWidth;
                        int y = i * height1 / newHeight;
                        resizedImage1(j, i, k) =
                            image1(x, y, k);
                    }
                }
            }
            // Resize image 2
            for (int i = 0; i < newHeight; i++)
            {
                for (int j = 0; j < newWidth; j++)
                {
                    for (int k = 0; k < image2.channels; k++)
                    {
                        int x = j * width2 / newWidth;
                        int y = i * height2 / newHeight;
                        resizedImage2(j, i, k) =
                            image2(x, y, k);
                    }
                }
            }
            // Merge the two resized images
            Image mergedImage(newWidth, newHeight);
            for (int i = 0; i < newHeight; i++)
            {
                for (int j = 0; j < newWidth; j++)
                {
                    for (int k = 0; k < image1.channels; k++)
                    {
                        mergedImage(j, i, k) =
                            (resizedImage1(j, i, k) +
                             resizedImage2(j, i, k)) / 2;
                    }
                }
            }
            mergedImage.save("merged_image.jpg");
        }
        // Option 2: Common area
        else if (option == 2)
        {
            int commonWidth = min(width1, width2);
            int commonHeight = min(height1, height2);
            Image mergedImage(commonWidth, commonHeight);
            for (int i = 0; i < commonHeight; i++)
            {
                for (int j = 0; j < commonWidth; j++)
                {
                    for (int k = 0; k < image1.channels; k++)
                    {
                        mergedImage(j, i, k) =
                            (image1(j, i, k) +
                             image2(j, i, k)) / 2;
                    }
                }
            }
        }
        
        }
    
    cout << "Images  got merged successfully".\n;

    // This function is used to apply sunlight filter
    
    void Sunlight(Image& image);
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            int red = image(j, i, 0)+50;
            if (red > 255) {
                red = 255;
            }
            image(j, i, 0) = red;
            int green = image(j, i, 1)+40;
            if (green > 255) {
                green = 255;
            }
            image(j, i, 1) = green;
            int blue = image(j, i, 2)-20;
            if (blue < 0) {
                blue = 0;
            }
        
            image(j, i, 2) = blue;
      cout << " Sunlight filter got applied".\n;
        }
    }
    
    
}


