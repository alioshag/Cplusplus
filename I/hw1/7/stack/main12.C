#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

stack s;
void test_size(int sz);

int main()
{
	const int x = 1000;

	for (int i = 0; i < stack_max_size; ++i) {
		test_size(i);
		s.push(x + i);
	}

	test_size(stack_max_size);

	for (int j = stack_max_size - 1; j >= 0; --j) {
		const int p = s.pop();
		if (p != x + j) {
			cerr << "element " << j << " should have been "
				<< x + j << ", but it was " << p << ".\n";
			return EXIT_FAILURE;
		}

		test_size(j);
	}

	test_size(0);
	cout << "Class stack passed test 1.\n";

	s.push(10);
	stack t = s;	//copy constructor
	t.push(20);
	if (s.size() != 1 || s.pop() != 10) {
		cerr << "Copy constructor damaged the stack that was copied.\n";
		return EXIT_FAILURE;
	}
	t.pop();
	t.pop();
	cout << "Class stack passed test 2.\n";
	return EXIT_SUCCESS;
}

void test_size(int size)
{
	const int sz = s.size();

	if (sz != size) {
		cerr << "size should have been " << size
			<< ", but it was " << sz << ".\n";
		exit(EXIT_FAILURE);
	}

	if (size <= 0 && !s.empty()) {
		cerr << "size == " << size
			<< ".  stack should have been empty, but it wasn't.\n";
		exit(EXIT_FAILURE);
	}

	if (size >= stack_max_size && !s.full()) {
		cerr << "size == " << size
			<< ".  stack should have been full, but it wasn't.\n";
		exit(EXIT_FAILURE);
	}
}
