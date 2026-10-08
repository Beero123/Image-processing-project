#define _CRT_SECURE_NO_WARNINGS
#include "Image_Class.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int x;
	string filename;
	cout << "Enter filename: ";
	getline(cin >> ws , filename);
	cout << "1. for white edges and "<< endl<< "2. for black edges "<< endl;
	cin >> x;
	Image image(filename);
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
			else if (x == 2)
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
	edge.saveImage("edgesImage.png");
}