/*******************************************
name: fraction.cpp
authot: Aliosha Gonzalez
date: 06/21/2013
synopsis: WK1 homework/chapter6/programming_projects_5
********************************************/


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cassert>
using namespace std;

class Fraction
{
        public:
                void output();   //output numerator and denominator
                void input();     //reads numenator and denominator
                void set(int n, int d); //set numerator and denominator
                void set(int n);   //sets fraction with denominator to 1 by default
                double division(); //returns a double with the value of the numerator divided by the demoninator
                void commonD();
                
        
        private:
                int N;   //numerator
                int D;   //denominator
                
};

int main ()
{
        Fraction F1, F2, F3;
        cout << "\nLets create the fraction F1\n";
        F1.input();
        F1.output();
        cout << "The CMD is: ";
        F1.commonD();
        F1.output();
        cout << "The division is: " << F1.division() << "\n";

        cout << "\nLets create the fraction F2 automatically\n";
        F2.set(3, 9);
        F2.output();
        cout << "The CMD is: ";
        F2.commonD();
        F2.output();
        cout << "\nLets change F2 manually\n";
        F2.input();
        F2.output();
        cout << "The CMD is: ";
        F2.commonD();
        F2.output();

        cout << "\nLets create a default fraction from an integer";
        F3.set(5);
        F3.output();


        return 0;
        
        
}
void Fraction::input()
{
        cout << "Enter and integer for the numerator: ";
        cin >> N;
        cout << "Enter a non zero integer for the denominator: ";
        cin >> D;

        if (D == 0)
        {
                cout << "Illegal denominator. Program aborted!\n";
                exit(1);
        }
                        
}

void Fraction::commonD()
{
        if (N != 0)
        {
                assert(N > 1 && D > 0);
                int i = min(N, D);
                for (; N % i > 0 || D % i > 0; --i) {
                }
                N /= i;
                D /= i;
        }
}
void Fraction::output()
{
        cout << "The fraction is " << N << " / " << D << endl;
}

void Fraction::set(int n, int d)
{
        if (d == 0)
        {
                cout << "Illegal denominator value! Program aborted.\n";
                exit(1);
        }
        N = n;
        D = d;
}
void Fraction::set(int n)
{
        N = n;
        D = 1;
}
double Fraction::division()
{
        return double(N) / D;
}
