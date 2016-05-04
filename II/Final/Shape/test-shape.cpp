/**********************************************
filename: "test-shape.cpp", final#2
author : Aliosha Gonzalez
synopsis: This is a test file for the classes derived from base class Shape.  
*********************************************/
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "doughnut.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void SortShape(Shape** Array, int NumShapes);

int main()
{
        Rectangle R1(15, 15, orange, 5, 10); //(x, y, base, height)
/*      cout << "Rectangle R1(15, 15, orange, 5, 10); //(x, y, base, height)\n";

        cout << "R1 Base= " << R1.getBase() << endl;
        cout << "R1 Height= " << R1.getHeight() << endl;
        
        //test mutators
        R1.setBase(2);   
        R1.setHeight(3);
        cout << "R1.setBase(2), Base= " << R1.getBase() << endl;
        cout << "R1.setHeight(3), Height= " << R1.getHeight() << endl;
        
        R1.setBase(5);     //return original base & height values
        R1.setHeight(10);
        cout << "R1.setBase(5), Base= " << R1.getBase() << endl;
        cout << "R1.setHeight(10), Height= " << R1.getHeight() << endl;
        
        cout << "R1 Area= " << R1.getArea() << endl;
        cout << "About to draw R1 --> ";R1.drawObject();

        //test operators
        Rectangle R2(5, 5, orange, 1, 1);
        cout << "Rectangle R2(5, 5, orange, 1, 1)\n";
        cout << "R2 Area= " << R2.getArea() << endl;
        
        Rectangle R3 = R1 + R2;
        cout << "R3 = R1 + R2\n";
        
        cout << "R3 Base= " << R3.getBase() << endl;
        cout << "R3 Height= " << R3.getHeight() << endl;
        cout << "R3 Area= " << R3.getArea() << endl;
        cout << "About to draw R3 --> ";R3.drawObject();
        cout << "Location of R3 --> (" << R3.getX() << ", " << R3.getY() << ")\n";

        cout << "Distance between R1 and R2 is " << getDistance(R1, R2) << endl;
*/        

        Circle C1(30, 30, red, 5);
        cout << "Circle C1(30, 30, red, 5)\n";
        cout << "C1 Area= " << C1.getArea() << endl;
/*        
        Circle C2(40, 40, red, 1);
        cout << "Circle C2(40, 40, red, 1)\n";
        cout << "C2 Area= " << C2.getArea() << endl;
        Circle C3 = C1 + C2;
        cout << "C3 Area= " << C3.getArea() << endl;
*/       
        
        Square S1(0, 0, yellow, 7);
        cout << "Square S1 (0, 0, yellow, 7)\n";
        cout << "S1 Area= " << S1.getArea() << endl;
/*        
        Square S2(40, 40, yellow, 2);
        cout << "Square S2(40, 40, yellow, 1)\n";
        cout << "S2 Area= " << S2.getArea() << endl;
        Square S3 = S1 + S2;
        cout << "S3 Area= " << S3.getArea() << endl;
        cout << "S3 Base= " << S3.getBase() << endl;
*/        
        Triangle T1(50, 50, green, 5, 10);
        cout << "Triangle T1(50, 50, green, 5, 10)\n";
        cout << "T1 Area= " << T1.getArea() << endl;
/*         
        Triangle T2(40, 40, green, 2, 4);
        cout << "Triangle T2(40, 40, green, 2, 4)\n";
        cout << "T2 Area= " << T2.getArea() << endl;
        Triangle T3 = T1 + T2;
        cout << "T3 Area= " << T3.getArea() << endl;
        cout << "T3 Base= " << T3.getBase() << endl;
        cout << "T3 Height= " << T3.getHeight() << endl;
*/        
        Doughnut D1(20, 20, black, 20, 10);
        cout << "Doughnut D1(20, 20, black, 20, 10)\n";
        cout << "D1 Area= " << D1.getArea() << endl;
/*
        cout << "About to draw D1 --> ";D1.drawObject();
        Doughnut D2(30, 30, black, 20, 5);
        cout << "D2 Area= " << D2.getArea() << endl;
       
        Doughnut D3 = D1 + D2;
        cout << "D3 = D1 + D2\n";
        cout << "D3 Area= " << D3.getArea() << endl;
        cout << "D3 Radius= " << D3.getRadius() << endl;
        cout << "D3 inRadius= " << D3.getInrad() << endl;
*/
//        Shape *p;
//        p = &R1;
//        cout << p->getArea() << endl;
        
        
        
        
        
//        Shape* ptr; //ptr of shapes
        
        Shape* a[5] = {&R1, &C1, &S1, &T1, &D1};  //Array of Base pointers pointing to the created shapes
/*        
      cout << a[0]->getArea() << endl;
      cout << a[1]->getArea() << endl;
      cout << a[2]->getArea() << endl;
*/
       
        
        Shape *cptr = &C1;
       //    cout << p[0]->getArea() << endl;
        SortShape(a, 5);//will sort array by ascendent figure areas
        for (int i = 0; i < 5; ++i) 
        {
                cout << a[i]->getArea() << endl;
                cout << "(" << a[i]->getX() << ", " << a[i]->getY() << ")" << endl;
                a[i]->ResetLocation(2,2);
                cout << "(" << a[i]->getX() << ", " << a[i]->getY() << ")" << endl;
                a[i]->print();
                a[i]->drawObject();
                cout << "Distance to the Circle=" << getDistance(*a[i], C1) << endl;
                cout << endl;
        }

        return 0;
}

void SortShape(Shape **Array, int NumShapes)
{
        //cout << Array[0]->getArea() << endl;
        
        for (Shape **end = Array + NumShapes -1; Array < end; --end) {
                for (Shape **p = Array; p < end; ++p) {
                        if (p[1]->getArea() < p[0]->getArea()) {
                                Shape* temp = p[0];
                                p[0] = p[1];
                                p[1] = temp;
                        }
                }
        }

/* 
        for (Shape **p = Array; p < Array + NumShapes; ++p) {
                cout << p->getArea() << endl;
        }
*/        
}

