/*****************************************
author: AliG
date: 06/21/2013
synopsis: test reference and pointers

****************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        int i = 5;
        int *pi = &i;
        int &ri = i;

        
        ri = ri + 1;
        cout << "ri = ri + 1;\n\n";

        cout << "i = " << i << "\n";
        
        cout << "the value of pi= addr = " <<  pi << "\n";
        cout << "the value of *pi= value = " <<  *pi << "\n\n";
        
        cout << "the value of ri= value = " <<  ri << "\n";
        cout << "the value of &ri= addr = " <<  &ri << "\n\n";

        
//        cout << "*pi = *pi + 1 ----> pi = " <<  pi << "\n";
//        cout << "the value of *pi = value = " <<  *pi << "\n\n";
        
//        cout << "the value of &ri+1 = addr = " <<  &ri+1 << "\n";
//        cout << "the value of ri+1 = value = " <<  ri+1 << "\n";
        
                
        return 0;
}
