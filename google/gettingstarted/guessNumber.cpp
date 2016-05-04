//guessNumber.cpp: AG

#include <iostream>
#include <cstdlib>
using namespace std;
int Generate_random();

int main()
{
        int rNumber = Generate_random();
        int input_var = 0;
        int guess_counter = 0;
        do {
                cout << "Guess our number (1 to 100) :";
                if (!(cin >> input_var))
                {
                        cout << "Please enter only numbers!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                } else
                {
                        guess_counter++;
                        if (input_var < rNumber) {
                                cout << "please go higher!\n";
                        } else if (input_var > rNumber) {
                                cout << "please go lower!\n";
                        }
                }
        }while (input_var != rNumber);
        cout << "Congratulation you won with " << guess_counter << " guess.\n";
        return 0;
}
int Generate_random()
{
        srand(time(NULL));
        return rand() % 100;
}
