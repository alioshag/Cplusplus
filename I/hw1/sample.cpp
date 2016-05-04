#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

main()
{
        cout << "Negative division --> " 
             << "-20 / 6 =" << -20 / 6 << "\n\n";
        cout << "Negative Remainder --> " 
             << "-20 % 6 =" << -20 % 6 << "\n\n";


        cout << "Begining loop from INT_MIN to INT_MAX \n"
             << "Please enter display factor \n";
        int factor;
        
        time_t now =time(0);
        char* dt = ctime(&now);
        cout << "This is the current time = " << dt << "\n\n";

        cin >> factor;

        if (!cin) {
                cerr << "Sorry but the factor has to be a number \n";
                return EXIT_FAILURE;        
        }
           
        for (int i=INT_MIN; i < INT_MAX; ++i) {
                if (i % factor == 0){
                       now =time(0);
                       dt = ctime(&now);
                       cout << i << dt << "\n";
               }
        }
        
        now =time(0);
        dt = ctime(&now);
        cout << "End of loop at = " << dt << "\n";
        return EXIT_SUCCESS;
}

