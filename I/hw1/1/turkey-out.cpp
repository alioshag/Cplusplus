//Homework INFO1-CE9264 
//date: 09/24/12
//name: Aliosha Gonzalez
//user: ag1917
//Filename turkey-out.cpp
//
#include <iostream>
#include <cstdlib>
#include <iomanip>    //for setfill and setw
using namespace std;

int main()
{       
        cout << "This program calculates the cooking time for a turkey \n" 
             << "Please enter the initial cooking time, first the hour ";
        int hour;
        cin >> hour;                                //input hour
        if (!cin) {
                cerr << "Input failed.\n";
                return EXIT_FAILURE;
        }
        if (hour < 0 || hour > 23) {
                cerr << "This value have to be in the range from 0 to 23 \n";
                return EXIT_FAILURE;
        }
        
        
        
        cout << "Please enter the minutes ";
        int min;
        cin >> min;                                  //input min
        if (!cin) {
                cerr << "Input failed.\n";
                return EXIT_FAILURE;
        }
        if (min < 0 || min > 59) {
                cerr << "This value have to be in the range from 0 to 59 \n";
                return EXIT_FAILURE;
        }
        

        cout << "Please enter the weight in pounds (The cooking time will be 4xmin per pound) ";

        int weight;
        cin >> weight;                                //input weigth
        if (!cin) {
                cerr << "Input failed.\n";
                return EXIT_FAILURE;
        }
        if (weight < 0) {
                cerr << "This value can not be negative \n";
                return EXIT_FAILURE;
        }
          
        int cdistance = 4 * weight;    //4m per pound
        int chour = cdistance / 60;       //convert distance to hours
        int cmin = cdistance % 60;        //convert distance to minutes
        int cday = chour / 24;            //convert distance in days
        
        cout << "\n";
        cout << "Cooking time is (hours mins) " << chour << " " << cmin << "\n";
        
        for (int i = 0; i < cdistance; ++i) {
                if (min < 59) {
                        ++min;
                        continue;
                }
                min = 0;
                if (hour < 23) {
                        ++hour;
                        continue;
                }
                hour = 0;
        }

        cout << "It will be ready at " << hour << ":";
        cout << setfill('0') << setw(2) << min << ".\n";
        return EXIT_SUCCESS;
}
