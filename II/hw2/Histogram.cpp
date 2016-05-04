/****************************************************************
name: Histogram.cpp
author: Aliosha Gonzalez
date: 06/25/2013
synopsis: Wk2 Chapter 7 Programming Project 8

*****************************************************************/


#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


vector<int> fillvector();    //Create and input vector list values
void sort(vector<int>& v);   //sort list
int indexOfSmallest(vector<int>& v, int index);    //returns the index of Smallest value left
void swapValues(int& a, int& b);    //swap values while sorting
void printHistogram(vector<int>& v);  //print the Histogram



int main()
{ 
        vector<int> Vgrades;
        cout << "Enter the grades. The minimun value of a grade is 0.\n"
             << "Place a -1 at the end.\n";

        Vgrades = fillvector();

        cout << "You entered: \n";
        for (unsigned int i = 0; i < Vgrades.size(); i++)
        {
                cout << Vgrades[i] << " ";
        }
        cout << "\n";
        
        sort(Vgrades);
        cout << "Sorted list: \n";
        for (unsigned int i = 0; i < Vgrades.size(); i++)
        {
                cout << Vgrades[i] << " ";
        }
        
        cout << "\nThe Histogram is: \n";
        printHistogram(Vgrades);
        
        return 0;
}
void printHistogram(vector<int>& v)
{
        int count=0, grade;
        if (v.size() > 0)
        {
                count = 1;
                grade = v[0];
        }
        for (int i = 0; i < v.size(); i++)
        {
                if (v[i] == v[i+1])
                {
                        count += 1;
                }else 
                {
                        cout << count << " with grade of " << grade << endl;
                        count = 1;
                        grade = v[i+1];
                }
        }
}
void sort(vector<int>& v)
{
        int indexNextSmall;
        for (int index = 0; index < v.size()-1; index++)
        {
                indexNextSmall = indexOfSmallest(v, index);
                swapValues(v[index], v[indexNextSmall]);
        }
}
int indexOfSmallest(vector<int>& v, int index)    //returns the index of Smallest value left
{
        int smallest_index = index;
        for (int i=index;i < v.size(); i++)
        {
                if (v[i] < v[smallest_index])
                                {
                                        smallest_index = i;
                                }
        }
        return smallest_index;
}
void swapValues(int& v1, int& v2)    //swap values while sorting
{
        int temp = v1;
        v1 = v2;
        v2 = temp;
}

vector<int> fillvector()
{
        vector<int> v;
        int next;
        cin >> next;
        while (next != -1)
        {
                if (next < -1)
                {
                        cout << "Illegal operation! Grades can not be negative. Program Aborted.";
                        exit(1);
                }
                v.push_back(next);
                cout << next << " added. ";
                cout << "v.size() = " << v.size() << endl;
                cin >> next;
        }
        return v;
}
