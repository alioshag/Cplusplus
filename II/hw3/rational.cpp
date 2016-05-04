/***********************************************************
name:rational.cpp
autor:AliG
date: June/2013
synopsis: Definition of class Rational and some overloading operators for the class
 
 
**********************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

class Rational
{
  public:
          Rational(int n, int d) : N(n), D(d) {;} //const with two arguments N/D
          Rational(int wholenumber) : N(wholenumber), D(1) {;} //const with one argument, denominator will initialize to N/1
          Rational() : N(0), D(1) {;} //Default const initialize to 0/1
          ~Rational() {}
          Rational(const Rational&) {cout << "copy constructor \n";}
          //overload >> and << operators. I/O in the form 1/2, 15/32, 200/401.Num and denom may contain minus sign -1/2, 15/-32, -300/-401.
          friend istream& operator >>(istream& inputStream, Rational& number);
          friend ostream& operator <<(ostream& outputStream, const Rational& number);
          
          //Overload the following operators ==, <, <=, >, >=, +, -, *, and /.
          friend bool operator ==(const Rational& number1, 
                          const Rational& number2){return ((number1.N * number2.D) == (number1.D * number2.N));}
          friend bool operator <(const Rational& number1, 
                          const Rational& number2){return ((number1.N * number2.D) < (number1.D * number2.N));}
          friend bool operator >(const Rational& number1, 
                          const Rational& number2) {number2 < number1;}
          friend bool operator <=(const Rational& number1, 
                          const Rational& number2) {number1 < number2 || number1 == number2;}
          friend bool operator >=(const Rational& number1, 
                          const Rational& number2) {number2 < number1 || number1 == number2;}
          friend Rational operator +(const Rational& number1, 
                          const Rational& number2)
                   {return Rational((number1.N * number2.D) + (number1.D * number2.N), number1.D * number2.D);}
          friend Rational operator -(const Rational& number1, 
                          const Rational& number2)
                   {return Rational((number1.N * number2.D) - (number1.D * number2.N), number1.D * number2.D);}
         friend Rational operator *(const Rational& number1, 
                         const Rational& number2) {return Rational(number1.N * number2.N, number1.D * number2.D);}
         friend Rational operator /(const Rational& number1, 
                         const Rational& number2) {return Rational(number1.N * number2.D, number1.D * number2.N);}
         //Normalize the values of rational numbers so denominators are positives and Num and Denom are as small as possible.
         void Normal(); 
         //Write a test program to test your class.
  private:
          int N;    //Numerator
          int D;    //Denominator
};        
int main ()
{
        Rational Number1, Number2;
        cout << "This is Number1 and Number2 defaults: " << Number1 << ", " << Number2 << "\n";
  
        cout << "Enter new values for a rational number1: ";
        cin >> Number1;
        cout << "Enter new values for a rational number2: ";
        cin >> Number2;
        
        cout << "\nThe rational numbers are: " << Number1 << " and " << Number2 << "\n";
        Number1.Normal();
        Number2.Normal();
        cout << "After normalization the rational numbers are: " << Number1 << " and " << Number2 << "\n";

        if (Number1 == Number2)
        {
                cout << Number1 << " == " << Number2 << "\n";
        }
        if (Number1 < Number2)
        {
                cout << Number1 << " < " << Number2 << "\n";
        }
        if (Number1 > Number2)
        {
                cout << Number1 << " > " << Number2 << "\n";
        }
        if (Number1 <= Number2)
        {
                cout << Number1 << " <= " << Number2 << "\n";
        }
        if (Number1 >= Number2)
        {
                cout << Number1 << " >= " << Number2 << "\n";
        }


        cout << Number1 << " + " << Number2 << " = " << Number1 + Number2 << "\n";
        cout << Number1 << " - " << Number2 << " = " << Number1 - Number2 << "\n";
        cout << Number1 << " * " << Number2 << " = " << Number1 * Number2 << "\n";
        cout << Number1 << " / " << Number2 << " = " << Number1 / Number2 << "\n";

        Rational Number3(4);
        cout << "The rational created with one integer argument is: " << Number3 << "\n";

        
        cout << "Number3 = Number1 + Number2 = ";
        Number3 = Number1 + Number2;
        Number3.Normal();
        cout << Number3 << "\n";

        return 0;
}
void Rational::Normal()
{
       int n = abs(N);
       int d = abs(D);
       if (n > 1) 
       {
               assert(n > 1 && d > 0);
               int i = min(n, d);
               for (; n % i > 0 || d % i > 0;--i)
               {
               }
               n /= i;
               d /= i;
       }        
       
       if ((N > 0 && D < 0) || (N < 0) && (D > 0))
               {
               n = -n;
               }
       
       N = n;
       D = d;
}
istream& operator >>(istream& inputStream, Rational& number)
{
        inputStream >> number.N;
        char sign;
        inputStream >> sign;
        if (sign != '/')
        {
                cout << "Illegal input!. This rational number does not have the rigth format of N/D. Program aborted.\n";
                exit(1);
        }
        inputStream >> number.D;
        return inputStream;
}
ostream& operator <<(ostream& outputStream, const Rational& number)
{       
       // if (number.N != 0) 
        {
                outputStream << number.N << '/' << number.D;
       // }else 
       //  {
       //          outputStream << number.N;
        }
        return outputStream;
}
