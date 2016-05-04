/*************************************************************
filename: mammal.cpp Midterm#2
author: Aliohsa Gonzalez
description: This is the implementation of the class Mammal.
             The interface is define in the file "mammal.h".
****************************************************************/

#include "mammal.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int Mammal::count = 0;   //stores the number of Mammals created

Mammal::Mammal() : DOB(), Weight(0)          //default CC
{
        Id = count++;
        cout << "Default CC of Mammal. id=" << Id << endl;
}
Mammal::Mammal(const Mammal& m)      //copy CC 
        :DOB(m.DOB), Weight(m.Weight), Id(m.Id) 
{
       cout << "Copy CC Mammal. id=" << Id << endl; 
}
Mammal::~Mammal()
{
        cout << "Destructor Mammal\n";
}
void Mammal::setMammal()
{
        cout << "Enter the weight: ";
        cin >> Weight;

        DOB.setdate();
}
int Mammal::getWeight()const{return Weight;}
int Mammal::getId() const{return Id;}
void Mammal::setDOB(){DOB.setdate();}
void Mammal::setWeight()
{
        cout << "Enter the new weight: ";
        cin >> Weight;
}
