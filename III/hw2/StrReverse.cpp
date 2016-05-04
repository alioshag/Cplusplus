/**********************************************************
 * filename: "StrReverse.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This program reverses the order of a string.
 * ********************************************************/

#include <string>
#include <iostream>
using namespace std;

main()
{
        string s1 = "madam";
        cout << "Please enter the string to reverse: ";
        cin >> s1;
        string s2;

        for (int i = 0; i < s1.size(); i++)
        {
                s2 = s1[i] + s2;
        }

        cout << s2 << endl;
}

              
