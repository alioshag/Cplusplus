#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        const int width = 300;                //number of columns of pixels
        const int heigth = width * 2 / 3;     //number of rows of pixel

        const int xmax = width / 2;           //place origin at center
        const int ymax = heigth / 2;
        const int xmin = xmax - width; 
        const int ymin = ymax - heigth;

        const int nstripes = 20;                //number of stripes
        const int npairs = nstripes / 2;        //number of pairs of stripes
        const int pairheight = heigth / npairs; //hight of each pair

        cout << "P3\n"                              //magic number of Netpbm .ppm file
                << width << " " << heigth << "\n"   //
                << 255 << "\n";                     //maximum color value; 0 is minimum
        

        //Draw a simplified American flag.
        //
        for (int y = ymax -1; y >= ymin; --y) {
                for (int x = xmin; x < xmax; ++x) {
                        if (x <= 0 && y >=0) {
                                //Upper left quadrant is blue union jack
                                cout << 0 << "\t" << 0 << "\t" << 255 << "\n";
                        } else if ((y - ymin) % pairheight < pairheight / 2) {
                                //white stripe
                                cout << 255 << "\t" << 255 << "\t" << 255 << "/n";
                        } else {
                                //red stripe
                                cout << 255 << "\t" << 0 << "\t" << 0 << "\n";
                        }
                }
        }
        return EXIT_SUCCESS;
}
