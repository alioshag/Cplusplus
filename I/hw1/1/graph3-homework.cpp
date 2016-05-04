//Homework INFO1-CE9264
//date: 09/24/12
//name: Aliosha Gonzalez
//user: ag1917
//filename: graph3-homework.cpp
//
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//Output graph paper.
        
	cout << "This program creates a graph paper. Please input the values of: \n" 
             << "How many rows (e.g., 10)? ";
	int nrows;	//uninitialized variable
	cin >> nrows;

        if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

	cout << "How many columns (e.g., 10)? ";
	int ncols;	//uninitialized variable
	cin >> ncols;

        if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

        cout << "How many rows of blanks in each box (e.g., 1)? ";
        int rblanks;    //uninitialized variable
        cin >> rblanks;

        if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

        cout << "How many columns of blanks on each box (e.g., 3)? ";
        int cblanks;    //uninitialized variable
        cin >> cblanks;

        if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

        
        
       for (int r = 0; r < nrows; ++r) {                          //main loop
               for (int c = 0; c < ncols; ++c) {                  //provides the "+"
                       cout << "+";
                       for (int cb = 0; cb < cblanks; ++cb) {     //provides the "----"
                               cout << "-";
                       }
               }
               cout << "\n";


               for (int rb = 0; rb < rblanks; ++rb) {                     //provides rows for "|     "
                       for (int c = 0; c < ncols; ++c) {                  //provides columns "|"
                               cout << "|";                               //provides blank columns "    "
                               for (int cb = 0; cb < cblanks; ++cb) {
                                       cout << " ";
                               }
                       }
                       cout << "\n";
               }
       } 
        
	
       return EXIT_SUCCESS;
}
