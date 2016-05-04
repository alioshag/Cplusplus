#include <iostream>
#include <list>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{
        std::cout << "argc =" << argc << std::endl;

        if (argc < 3) 
        {
                std::cout << "The number of arguments should be two or more. Program abort !!!\n";
                EXIT_FAILURE;                
        }

        --argc;

        std::cout << argv[argc] << " ";
        for (int i = 1; i < (argc); i++)
                std::cout << argv[i] << " ";

        std::cout << std::endl;
        return 0;
}       
