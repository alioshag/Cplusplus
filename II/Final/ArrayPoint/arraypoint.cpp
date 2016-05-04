/*******************************************************************
filename: "apoint.cpp". final#3
author : Aliosha Gonzalez
synopsis: This is a program that creates an array of points using the
          class template interface in file "pointtemplate.h" and defintion
          in file "pointtemplate.cpp".
***************************************************************/
#include "pointtemplate.h"
#include "pointtemplate.cpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
        Point<double> a[10];
        
        for (int i = 0; i < 10; ++i) {
                cout << "Creating array -->" << i << "," << i << endl;
                a[i].reset_location(i,i);
        }

        //writing array of points into "Point.dat" file.
        //ofstream outStream; //declaration of stream outStream as a ofstream
        //outStream.open("Point.dat");//connect output stream to a file
        ofstream outStream("Point.dat", ios::trunc);//combine the two lines before,ios::app append
        if (outStream.fail())
        {
                cout << "Output file opening failed.\n";
                exit(1);
        }
        cout << "Writing array on file 'Point.dat'\n";
        for (int i = 0; i < 10; ++i)
        {
                outStream.write((char*)&a[i], sizeof(Point<double>));
        }
        outStream.close();
        
        //reading from file
        ifstream inStream("Point.dat", ios::in);//reopen file
        if (inStream.fail())
        {
                cout << "Input file opening failed.\n";
                exit(1);
        }
        cout << "Reading array from file 'Point.dat'\n";
        for (int i = 0; i < 10; ++i)
        {
               //inStream >> b[i];
               inStream.read((char*)&a[i], sizeof(Point<double>));// read in reverse order
        }
        inStream.close();
        
        //multiply file content by a factor 2
        cout << "Multiplying obj coordinates on array for factor 2\n";
        for (int i = 0; i < 10; ++i)
        {
                a[i].reset_location(a[i].getX()*2, a[i].getY()*2);
        }
        //write the changes to a file
        outStream.open("Point.dat", ios::trunc);
        if (outStream.fail())
        {
                cout << "Output file opening failed.\n";
                exit(1);
        }
        cout << "Writing changes to the file 'Point.dat'\n";
        for (int i = 0; i < 10; ++i)
        {
                outStream.write((char*)&a[i], sizeof(Point<double>));
        }
        outStream.close();

        //reads the new file
        inStream.open("Point.dat", ios::in);
        if (inStream.fail())
        {
                cout << "Input file opening failed.\n";
                exit(1);
        }
        cout << "Reading the file with new changes\n";
        for (int i = 0; i < 10; ++i)
        {
               inStream.read((char*)&a[i], sizeof(Point<double>));// read in reverse order
        }
        inStream.close();
        //print new file content
        for (int i = 0; i < 10; ++i)
        {
                cout << a[i];
        }
        
        return 0;
}
