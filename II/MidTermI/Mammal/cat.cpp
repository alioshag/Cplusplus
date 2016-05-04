/**********************************************************
filename: "cat.cpp"  Midterm#2
author: Aliosha Gonzalez
synopsis: This file is the implementation of the class Cat. 
          The interface of the class Cat is in the file "cat.h"
 *
 * ************************************************************/
#include "cat.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Cat::Cat() : CatType(), Jcolor(NOCOLOR), Mammal()
{
//        CatType = 'No Type Yet';
        cout << "Default CC of Cat" << endl;
}
Cat::~Cat()
{
        cout << "Destructor of Cat\n";
}
ostream& operator<<(ostream& out, const Cat &c)
{
        out << "CatType= " << c.getCatType() << endl
                << "color= " << c.getColor() << endl
                << "Id= " << c.getId() << endl
                << "Weight= " << c.getWeight() << endl
                << "dob: " << c.DOB << endl
                << "dates from birth: " << Date(7,1,2013) - c.DOB << endl;

        return out;
}
