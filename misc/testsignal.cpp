/*****************************
 * filename: "testsignal.cpp"
 * author: AG
 * synopsis: The program captures its process number and sends itself a stop signal.
 * ***************************************/
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>


int main()
{
        pid_t my_pid = getpid();
        std::cout << "my process is " << getpid() << std::endl;
        std::cin.get();

        kill(my_pid, SIGSTOP);
        std::cin.get();
        return 0;
}
