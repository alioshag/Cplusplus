/**********************************************************************
filename: "cat.h" Midterm#2
author: Aliosha Gonzalez
synopsis: Interface for the class Cat. The implementation is on the file "cat.cpp"
 *
 *
 *
 *
 *
 * ***********************************************************************/
#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "mammal.h"

class Cat : public Mammal
{
        private:
                string CatType;     //Persian, Afghan, etc...
                int Jcolor;         //Color_t color;
                Cat(); //private to avoid the creating of a cat with zero info
                enum Color_t {NOCOLOR=0, BLUE, GREY, RED, BLACK, WHITE, BROWN};
        public:
                Cat(string cattype, int jcolor, const int &weight, const Date &d)
                        : CatType(cattype), Jcolor(jcolor), Mammal(weight, d)
                        {cout << "Cat CC\n";}
                Cat(const Cat& c) 
                        : Mammal(c), CatType(c.CatType), Jcolor(c.Jcolor)
                        {cout << "Copy CC cat\n";}
                ~Cat();
                
                //accessors
                string getCatType() const{return CatType;}
                int getColor() const{return Jcolor;}

                //mutators
                void setType();
                void setColor();

                //friend functions
                friend ostream& operator<<(ostream& out, const Cat &c);
};
#endif  //CAT_H
