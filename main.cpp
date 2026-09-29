#include "Image_Class.h"
#include <iostream>
using namespace std;
int main()
{
    string filename;
    cout<< "Enter the filename:";
    cin>> filename;
    Image image(filename);

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
    image.saveImage("gray.jpg");
    cout << "Image is grayscaled" << endl;
    return 0;
}
