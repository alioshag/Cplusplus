/*****************************************************
 * filename: "textEditor.cpp"
 * author: Aliosha Gonzalez
 * synopsis: Creates a text editor using STL. 
 * ****************************************************/

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <algorithm>
static int beginN, endN; //begining and ending of a range

//print lines
void printLines(std::list<std::string>::iterator it, int Size)
{
        std::cout << "printing lines\n";
        for (int i = 0; i < Size; i++)
        {
                std::cout << i+1 << ": " << *it << std::endl;
                it++;
        }
}
//print the menu
void printMenu()
{
        std::cout << "\n\n";
        std::cout << "(I) - insert line\n";
        std::cout << "(A) - append line\n";
        std::cout << "(M) - move line from line #xxx to #yyy at line #zzz\n";
        std::cout << "(D) - delete from line #xxx to #yyy\n";
        std::cout << "(F) - find lines containing a target word\n";
        std::cout << "(S) - sort lines\n";
        std::cout << "(P) - print lines\n";
        std::cout << "(Q) - quit\n\n";
        std::cout << "Please enter your choice: ";
}
//inserts newList in theList at insert target
std::list<std::string>& insert_(std::list<std::string>& theList, std::list<std::string>& newList, int insertAt)
{
        std::list<std::string>::iterator list_it = theList.begin();//iter on the original list
        advance(list_it, insertAt);//advance list_it to the insertion position
        std::copy(newList.begin(), newList.end(), std::inserter(theList,list_it)); //insertion
        return theList;
}
//inserts new line at target posicion. Posicion requested by standard input
std::list<std::string>& inputInsert(std::list<std::string>& theList)
{
        std::cout << "New line will be inserted after insert posicion.\n";
        std::cout << "Enter insert posicion from [0..N]: ";
        
        //test for correct standard input
        std::string badChars;
        int insertAt;
        if (!(std::cin >> insertAt)) 
        {
                std::cerr << "Input error. Back to the main menu\n";
                std::cin.clear(); //clears the stream
                std::cin >> badChars; //in case of letters remove letters from stream
                return theList;
        }
        
        //test for correct range
        if (insertAt < 0 || insertAt > theList.size())
        {
                std::cerr << "Out of range. Back to the main menu!.";
                return theList;
        }
        
        //Enter new line
        std::cin.ignore(); //clear the newline \n from the istream
        std::cout << "Enter the new line text: ";
        std::string newLine;
        std::getline (std::cin, newLine);
        
        //create newLlist with newLine
        std::list<std::string> newList(1, newLine);

        //call to insert_ to inserts newList in theList at insertAt
        insert_(theList, newList, insertAt);
        return theList;
}
//append a new line at the end the the list
std::list<std::string>& append_(std::list<std::string>& theList)
{
        std::cout << "Enter the new line text: ";
        std::string newLine;
        std::getline(std::cin, newLine);
        theList.push_back(newLine);
        return theList;
}
//erase lines from the range [beginN..endN] which are global
std::list<std::string>& erase_(std::list<std::string>& theList)
{
        std::list<std::string>::iterator it1 = theList.begin();
        //it1, place at the beginN of the range position on the list
        advance(it1, beginN-1); //-1 to correct for list range[0..n-1]

        std::list<std::string>::iterator it2 = theList.begin();
        //it2, place at the endN of the range position on the list
        advance(it2, endN-1);//-1 to correct for list range[0..n-1]
        theList.erase (it1, ++it2);  //+1 to include the ending line to delete
        return theList;
}
//sets beginN and endN of the range through standard input
bool inputRange(int size)
{
        std::string badChars;
        std::cout << "Enter the initial line: ";
        //test for correct standard input
        if (!(std::cin >> beginN))
        {
                std::cerr << "Input error. Back to the main menu\n";
                std::cin.clear(); //clears the stream
                std::cin >> badChars; //clears letter from stream
                return false;
        }
        std::cin.ignore();
        
        std::cout << "Enter the last line: ";
        //test correct standard input
        if (!(std::cin >> endN))
        {
                std::cerr << "Input error. Back to the main menu\n";
                std::cin.clear(); //clears the stream
                std::cin >> badChars; //clears letter from stream
                return false;
        }

        std::cin.ignore();
        //test for correct range
        if (beginN < 1 || beginN > size || endN < 1 || endN > size || beginN > endN)
        {
                std::cerr << "\n\nRange error. Back to the main menu!.\n";
                return false;
        }
        return true;
}
//creates a new list with the range, deletes range elements, insert new list in target
std::list<std::string>& move_(std::list<std::string>& theList)
{
        std::string badChars;
        std::cout << "Enter the target line posicion: ";
        int targetLine;
        
        //test/target line correct standard input
        if (!(std::cin >> targetLine))
        {
                std::cerr << "Input error. Back to the main menu\n";
                std::cin.clear(); //clears the stream
                std::cin >> badChars; //clears letter from stream
                return theList;
        }
        
        std::cin.ignore();//cleans newline \n from the stream
        
        //test range of the target line
        if (targetLine < 1 || targetLine > theList.size())
        {
                std::cerr << "\n\nTarget line error. Back to the main menu!.\n";
                return theList;
        }

        
        std::list<std::string>::iterator it1 = theList.begin();
        std::list<std::string>::iterator it2 = theList.begin();
        advance(it1, beginN-1);
        advance(it2, endN-1);

#ifdef _DEBUG        
        std::cout << "it1: " << *it1 << std::endl;
        std::cout << "it2: " << *it2 << std::endl;
        std::cin.get();
#endif       
        //create newList
        std::list<std::string> newList(endN - beginN + 1);
        std::copy( it1, ++it2, newList.begin()); //++it2,copy command does not include the last element

#ifdef _DEBUG        
        std::cout << "created new list\n\n";
        printLines(newList.begin(), newList.size());
        std::cin.get();
#endif

        //delete elements from original list
        erase_(theList);  //uses global beginN, endN

#ifdef _DEBUG        
        std::cout << "erased elements from original\n\n";
        printLines(theList.begin(), theList.size());
        std::cin.get();
#endif
        //corrects when target is > than begin of range
        if (targetLine > beginN) targetLine = targetLine - (endN - beginN + 1);
        //insert newlist into original list at target
        insert_(theList, newList, targetLine-1); //list begins in zero

#ifdef _DEBUG
        std::cout << "final list\n\n";
        printLines(theList.begin(), theList.size());
        std::cin.get();
#endif        
        return theList;
}
void findWord(std::list<std::string>& theList)
{
        std::cout << "Enter word to find: ";
        std::string word;
        std::cin >> word;
        std::cin.ignore();

        std::list<std::string>::iterator it = theList.begin();
        std::size_t count = 0;
        for (int i = 0; i < theList.size(); i++)  
        {
                if ((*it).find(word) != std::string::npos)
                {
                        std::cout << i+1 << ": " << *it << std::endl;
                        ++count;  //count number of lines where word was found
                }
                ++it;
        }
        if (count == 0) std::cout << "Sorry no line found containing the target word.\n";
}
int main()
{
        std::cout << "Enter some text lines. Enter '#' to end.\n";
        std::list<std::string> list_;
        std::list<std::string>::iterator list_it;
        std::string str = "";
        
        while (str != "#" && list_.size() < 40)
        {
                std::getline (std::cin, str);
                //std::cin.ignore();
                if (str != "#") list_.push_back(str);
        }
        printLines(list_.begin(), list_.size());
        
        char key = ' ';
        while (key != 'q' && key != 'Q')
        {
                printMenu();
                std::cin >> key;
                std::cin.ignore();
                switch (key)
                {
                        case 'I':
                        case 'i':
                                list_ = inputInsert(list_);
                                break;
                        case 'A':
                        case 'a':
                                list_ = append_(list_);
                                break;
                        case 'M':
                        case 'm':
                                if (inputRange(list_.size())) list_ = move_(list_);
                                break;
                        case 'D':
                        case 'd':
                                if (inputRange(list_.size())) list_ = erase_(list_);
                                break;
                        case 'F':
                        case 'f':
                                findWord(list_);
                                break;
                        case 'P':
                        case 'p':
                                 printLines(list_.begin(), list_.size());
                                 break;
                        case 'S':
                        case 's':
                                 list_.sort();
                                 break;
                        case 'Q':
                        case 'q':
                                std::cout << "Program Exit!.\n\n";
                                break;
                }
        }
        return 0;
}
