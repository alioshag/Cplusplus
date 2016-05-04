#include <iostream>
#include <cstdlib>
#include <complex>
using namespace std;

/*
Mandelbrot set
As x goes from xmin to xmax, scaledX goes from -2.5 to 2.5.
*/

int main()
{
	const int width = 1012;
	const int height = width * 2 / 3;

	const int xmax = width / 2;
	const int ymax = height / 2;
	const int xmin = xmax - width;
	const int ymin = ymax - height;

	cout << "P3\n"		//Netpbm .ppm file
		<< width << " " << height << "\n"
		<< 255 << "\n";

	const double scale = 2.5 / (width / 2.0);	//magnify the picture
	const int n = 100;

	for (int y = ymax - 1; y >= -ymax; --y) {	//top to bottom
		for (int x = -xmax; x < xmax; ++x) {	//left to right
			const double scaledX = x * scale;
			const double scaledY = y * scale;

			complex<double> z(0);
			const complex<double> c(scaledX, scaledY);

			for (int i = 0; i < n; ++i) {
				if (abs(z) >= 2.0) {
					//white: c does not belong to the set.
					cout << 255 << "\t" << 255 << "\t" << 255;
					goto done;
				}

				z *= z;
				z += c;
			}

			//black: c does belong to the set.
			cout << 0 << "\t" << 0 << "\t" << 0;
			done:;
			cout << "\n";
		}
	}

	return EXIT_SUCCESS;
}
