#include <iostream>
#include <cstdlib>
#include <string>	//for string
using namespace std;

struct month {
	int length;	//number of days
	string name;
};

int main()
{
	month a[] = {
		{31, "January"},
		{28, "February"},
		{31, "March"},
		{30, "April"},
		{31, "May"},
		{30, "June"},
		{31, "July"},
		{31, "August"},
		{30, "September"},
		{31, "October"},
		{30, "November"},
		{31, "December"}
	};
	const size_t n = sizeof a / sizeof a[0];

	cout << a[0].length << " " << a[0].name << "\n";

	cout << "Length and name of each month:\n";
	for (size_t i = 0; i < n; ++i) {
		cout << a[i].length << " " << a[i].name << "\n";
	}
	cout << "\n";

	int sum = 0;
	for (size_t i = 0; i < n; ++i) {
		sum += a[i].length;	//means sum = sum + a[i].length
	}

	cout << "A year has " << sum << " days.\n";
	return EXIT_SUCCESS;
}
