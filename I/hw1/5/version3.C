//version3.C p.115
//Call member functions of an object
#include <iostream>
#include <cstdlib>
using namespace std;


const int date_length[] = {
        0,   //dummy element so that January will have subscript 1
        31,   //January
        28,   //February
        31,   //March
        30,   //April
        31,   //May
        30,   //June
        31,   //July
        31,   //August
        30,   //September
        31,  //October
        30,  //November
        31   //December            
};

class date {
        int year;
        int month;             //1 to 12 inclusive
        int day;               //1 to date_length[month] inclusive
public:
        date(int initial_month, int initial_day, int initial_year);
        void next(int count);    //Go count days forward
        void next();             //Go one day forward
        void print() const;      //Output date to cout
};


int main()
{       
        //Construct d by passing three arguments to the constructor for d
        date d(1, 1, 2012);

        cout << "How many days forward from ";
        d.print();
        cout << " would you want to go? ";
        
        int count;      //uninitialized variable
        cin >> count; 

        d.next(count);
        
        cout << "The due day will be in => ";
        d.print();
        cout << "\n";
        

        return EXIT_SUCCESS;

}

date::date(int initial_month, int initial_day, int initial_year)
{
        if (initial_month < 1 || initial_month > 12) {
                cerr << "bad month " << initial_month << "/" << initial_day 
                        << "/" << initial_year << "\n";
                exit(EXIT_FAILURE);
        }
        if (initial_day < 1 || initial_day > date_length[initial_month]) {
                cerr << "bad date " << initial_month << "/" << initial_day
                        << "/" << initial_year << "\n";
                exit(EXIT_FAILURE);
        }
        year = initial_year;
        month = initial_month;
        day = initial_day;
}

void date::print() const      //This is the funcion definition
{
        cout << month << "/" << day << "/" << year;
}
void date::next(int count) //call through function
{
        while (--count >= 0) {
                next();
        }
}
void date::next()   //date is a class
{
        if (++day > date_length[month]) {
                day = 1;
                if (++month > 12) {
                        month = 1;
                        ++year;
                }
        }
}
