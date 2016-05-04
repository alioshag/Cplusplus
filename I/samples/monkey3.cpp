#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "What year were you born? ";
	size_t year;	//uninitialized variable
	cin >> year;
	if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

	cout << year << " was the year of the ";

	switch (year % 12) {
	case 0:
		cout << "monkey";
		break;
	case 1:
		cout << "rooster";
		break;
	case 2:
		cout << "dog";
		break;
	case 3:
		cout << "pig";
		break;
	case 4:
		cout << "rat";
		break;
	case 5:
		cout << "ox";
		break;
	case 6:
		cout << "tiger";
		break;
	case 7:
		cout << "hare";
		break;
	case 8:
		cout << "dragon";
		break;
	case 9:
		cout << "snake";
		break;
	case 10:
		cout << "horse";
		break;
	case 11:
		cout << "sheep";
		break;
	}

	cout << ".\n";
	return EXIT_SUCCESS;
}
