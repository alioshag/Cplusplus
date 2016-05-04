//gcd_euclidean.cpp: AG
//description: finds the great common denumerator using euclidean method
#include <iostream>
#include <cstdlib>
#include <locale>
using namespace std;

//int main()
int main(int argc, char* argv[])
{
/*        
        int numerator = 0;
        int denominator = 0;
*/      
        cout << "argc= " << argc << endl;
        if (argc != 3) {
                cerr << "Missin arguments. Program abort!" << endl;
                exit(1);
        }

        locale loc;
        int numerator = 0; 
        int denominator = 0;
        int reminder = 0;

        if (!(cin >> numerator)) cout << "numerator needs to be a number\n";
                        else cout << "numerator= " << numerator << endl;

        exit(0);                
        
        numerator = atoi(argv[1]);
        cout << "numerator= " << numerator << endl;
        
        if (isdigit(argv[1], loc)) {
                numerator = (int)(argv[1]);
                cout << "numerator= " << numerator << endl;
        }else {
                cout << "arguments needs to be numbers. program abort!\n";
                exit(1);
        }
        


        
//input variables        
        do 
        {
                cout << "Input numerator: ";
                if (!(cin >> numerator) or (numerator <=0)) {
                        cout << "numerator has to be a number greater than zero!\n";
                        //clear cin from input errors
                        cin.clear();
                        cin.ignore(1000,'\n');
                }
        } while (numerator <= 0);
        
        do {
                cout << "input denominator: ";
                if (!(cin >> denominator) or (denominator <=0)) {
                        cout << "denominator needs to be a number greater than zero\n";
                        //clear cin from input errors
                        cin.clear();
                        cin.ignore(1000,'\n');
                }
        } while (denominator <= 0);

        
//swap values if numerator < denominator
        if (numerator < denominator) {
                int temp = denominator;
                denominator = numerator;
                numerator = temp;
        }
        
//do the algorithm
do {
        reminder = numerator % denominator;
        if (reminder > 0) {
                numerator = denominator;
                denominator = reminder;
        }else if (reminder < 0) {
                cout << "the GCD is 1.\n";
                //break;
        }else if (reminder == 0) {
                cout << "the gcd = " << denominator << endl;
                //break;
        }
}while (reminder > 0);        
                
        return 0;
}
        
