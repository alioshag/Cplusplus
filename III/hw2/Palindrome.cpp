/*************************************************
 * filename: "Palindrome.cpp"
 * author: Aliosha Gonzalez
 * synopsis: The program takes a string argument from the commmand line and returns TRUE           if the string is palindrome.
 * ****************************************************************/

#include <string>
#include <iostream>
using namespace std;

bool palindrome(string s)
{
        //build ReverseStr
        string ReverseStr;
        for (int i = 0; i < s.size(); i++)
        {
                ReverseStr = s[i] + ReverseStr;
        } //cout << ReverseStr << endl;

        //Compare ReverseStr with original string s to check for palindrome
        for (int i = 0; i < s.size(); i++)  //iterates through the chars of the whole string
        {
                if (s[i] != ReverseStr[i])  //check for palindrome
                {
                        return false;
                        break;
                }           
        }
        
        return true;
}
int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                cerr << "Expecting one command line argument. Program abort!" << endl;
                return EXIT_FAILURE;
        }
        
        if (palindrome(argv[1]))
        {
                cout << "TRUE" << endl;
        }else
        {
                cout << "FALSE" << endl;
        };
        
        return 0;
}
                
