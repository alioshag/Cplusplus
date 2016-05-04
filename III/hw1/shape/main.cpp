/***************************************************
 * filename: "main.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This is the test file for the base class Shape and its derived classes Circle, Tringle and Square.
 * *************************************************************/
#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        //Shape S2(1, 1);
        Circle C1(1, 1, 2);
        //C1.draw();
        Square S1(1, 1, 3);
        //S1.draw();
        Triangle T1(1, 1, 2, 3);
        //T1.draw();

        Shape *a[3] = {&C1, &S1, &T1};

        for (int i=0; i < 3; ++i)
        {
                a[i]->draw();
        }

        return 0;
        
}
