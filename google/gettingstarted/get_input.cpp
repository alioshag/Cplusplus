//get_input.cpp: AG
//description: the program recovers from an input error
#include <iostream>
using namespace std;

int main(){

        int input_var = 0;
        do {
                cout << "Enter a number or -1 to quit: ";
                if (!(cin >> input_var)) {
                        cout << "Non-numeric input\n";
                        cin.clear();
                        cin.ignore(10000,'\n');
                } else {
                        if (input_var != -1)
                                cout << "you entered " << input_var << endl;
                }
        } while (input_var != -1);

        cout << "Exit\n";

        return 0;
}
        
