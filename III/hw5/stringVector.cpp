/******************************************************
 * filename: "stringVector.cpp"
 * author: Aliosha Gonzalez
 * synopsis: Work with vector containers
 * ***************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
        string array[5] = {"1", "2", "3", "4", "5"};
        vector <string> s_v(5);
        
        for (int i = 0; i < sizeof array / sizeof array[0]; i++)
                s_v[i] = array[i];
        
        s_v.push_back("6");
        s_v.push_back("7");
        s_v.push_back("8");
        s_v.push_back("9");
        s_v.push_back("10");

        cout << "vector strings\n";
        for (int i=0; i < s_v.size(); i++)
                cout << s_v[i]<< " ";

        //One way to swaping elements 2nd and 4th
        /*
        vector<string>::iterator p1;
        vector<string>::iterator p2;
        p1 = s_v.begin() + 1;  //2nd element
        p2 = s_v.begin() + 3;  //4th element
        string temp = *p1;     
        *p1 = *p2;
        *p2 = temp;
        */

        //Swapping elements using STL
        iter_swap(s_v.begin() + 1, s_v.begin() + 3);
        cout << "\nvector strings after swaping second and fourth elements\n";
        for (int i=0; i< s_v.size(); i++)
                cout << s_v[i] << " ";
        cout << endl;

        //list part
        cout << "\nlist1= 0,1,2 and list2= 10,11,12.\nAfter merging both lists on list1\n";
        list<int> first;
        list<int> second;

        first.push_back(0);
        first.push_back(1);
        first.push_back(2);

        second.push_back(10);
        second.push_back(11);
        second.push_back(12);

        list<int>::iterator it1 = first.end();
        list<int>::iterator it2 = second.begin();
        first.merge(second);

        for (list<int>::iterator iti = first.begin(); iti != first.end(); ++iti)
                cout << *iti << ", ";
        cout << endl;

        //set part
        

        return(0);
};
