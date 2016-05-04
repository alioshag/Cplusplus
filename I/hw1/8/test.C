//Filename test.C 
//Description: test pointer to an arraay of struct
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct str {
        string name;
        double id;
};

str a[] = {
        {"ali", 37},
        {"Moe", 36},
        {"Mir", 62}
};

const size_t n = sizeof a / sizeof a[0];

int main()
{
        for (const str *p=a; p < a + n; ++p){
                cout << p->name << "\n";
        }

        cout << "Please choose and type in one of the names shown above: ";
        string choice;
        cin >> choice;

        for (const str *p=a; p < a + n; ++p) {
                if (p->name == choice) {
                        cout << "found " << p->name << "\n";
                        return EXIT_SUCCESS;
                }
        }

        cerr << choice << " not found\n";
        return EXIT_FAILURE;
}
