/*******************************************
 * filename: /home/agonzale/code/C++/misc/threding/threading1.cpp
 * description: testing threading
 * *******************************************/
#include <iostream>
#include <thread>

void function_1()
{
  std::cout << "Hello World!" << std::endl;
}
int main()
{
  function_1();
  return 0;
}




