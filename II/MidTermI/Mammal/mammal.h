/******************************************************************
filename: mammal.h
author: Aliosha Gonzalez
synopsis: Midterm #2
2.  (30%) Write a C++ application program that creates a simple Mammal/Cat hierarchy  class having the following attributes:

        Class Mammal{
        a.      Int Weight
        b.      Int Id 
        c.      static int count
        d.      Date of Birth(DOB) (represented by Date object (day/month/year) - composition
        e.      Constructors/Destructors/Copy Constructors
        f.      Assign each Mammal Id to the count value update in the constructor
        g.      Mutators and Accessors
        h.      The Date class should consist of a simple Date class containing 
        i.      int day/int month/ int year
        ii.     Constructors/Destructors
        iii.    Mutators and Accessors
        iv.     Overloaded operators (+, -, =)
        };
                Class Cat{
                i.      Create a Cat class derived from Mammal that contains the following members
                i.      String CatType(e.g. Persian, Afghan, etc)
                ii.     enum COLOR (White, Black, Gray, etc)
                iii.    Constructors/Destructors/Copy Constructors
                iv.     Mutators and Accessors
                j.      Instantiate  an array of three cats
                k.      Assign each cat a different Color, Weight, DOB
                l.      Create a global function called ChangeWeight(Mammal &X) that changes the weight of the mammal
                m.      Print for all instantiated cats a list of all of its attributes (Weight, Color, Id, Number of Days since birth (Assume today’s date to be Jul 1, 2013)
                n.      Print the total number of Mammals in existence
                };
                
 

 
********************************************************************/
#ifndef MAMMAL_H
#define MAMMAL_H
#include "date.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class Mammal
{
        protected:
                int Weight;
                int Id;
                static int count;
                Date DOB;
                Mammal(); //private to avoid creating mammals with no info  //default CC
        public:
                Mammal(int weight, const Date &d)
                        :Weight(weight), DOB(d){Id = count++;cout << "CC for Mammal\n";}
                Mammal(int weight)
                        :Weight(weight), DOB(){Id = count++;cout << "One arg CC Mammal\n";}
                Mammal(const Mammal& m); // "copy CC "
                ~Mammal();                //ok  
                //accessors
                int getWeight() const;
                int getId() const;
                
                //mutators
                void setDOB(); //change the DOB
                void setWeight(); //set the weight
                void setMammal();     //ok sets the info inputing from keyboard
                void print() const;      //ok prints Obj information id, weight, dob

                //friend functions
                friend int CountMammal(){return count;}
                friend ostream& operator<<(ostream& out, const Mammal &m)
                {
                        out << "Id= " << m.getId() << endl
                                << "Weight= " << m.getWeight() << endl
                                << "dob: " << m.DOB << endl;
                        return out;
                }
};
#endif  //MAMMAL_H
