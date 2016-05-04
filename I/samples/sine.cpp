#include <iostream>
#include <cstdlib>
#include <cmath>	//for sin
using namespace std;

/*
As x goes from xmin to xmax, scaledX goes from -2 * pi to 2 * pi.

The value of sin is multiplied by scale to stretch it vertically.
Without this stretch, the value would be in the range -1 to 1,
too small to see.
The static_cast<int>() converts the return value of sin from double to int,
so it will fit into s without warnings.
*/

int main()
{
	const int width = 600;
	const int height = width * 2 / 3;

	const int xmax = width / 2;
	const int ymax = height / 2;
	const int xmin = xmax - width;
	const int ymin = ymax - height;

	cout << "P3\n"		//Netpbm .ppm file
		<< width << " " << height << "\n"
		<< 255 << "\n";

	const double pi = 3.14159265358979323846;
	const double scale = xmax / (2 * pi);

	for (int y = ymax - 1; y >= -ymax; --y) {	//top to bottom
		for (int x = -xmax; x < xmax; ++x) {	//left to right

			const double scaledX = x / scale;
			const double value = sin(scaledX);	//the punchline
			const int scaledY = static_cast<int>(value * scale);

			if (scaledY == y) {
				//black curve
				cout << 0 << "\t" << 0 << "\t" << 0;
			} else if (x == 0 || y == 0) {
				//blue axis
				cout << 0 << "\t" << 0 << "\t" << 255;
			} else {
				//white background
				cout << 255 << "\t" << 255 << "\t" << 255;
			}
			cout << "\n";
		}
	}

	return EXIT_SUCCESS;
}
