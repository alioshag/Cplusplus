/**************************************************
 * filename: "datacompression.cpp"
 * author: Aliosha Gonzalez
 * synopsis: compress data from a text file, creating a set and bitset table
 * *******************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
#include <bitset>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
//using std::string;
using std::set;
using std::bitset;
//#define _DEBUG

//put text on a std::string using the extraction operator>>
std::string getText(char* filename)
{
        std::string text = "";
        ifstream ifs;
        ifs.open(filename);
        if (ifs.fail()) {cout << "Input file opening failed.\n"; exit(1);}
        std::string word = "";
        
        while (ifs >> word) //extractor operator>> in action
                text += word + " ";

        ifs.close();
        return text;
}
//add spaces around punctuation and symbols. Converts to uppercase
std::string& massageText(std::string& text_)
{
        size_t found = text_.find_first_of(".,;:-&"); //returns punct pos in found
        
        while (found != std::string::npos)       //std::string::npos -> end of the std::string
        {
                text_.insert(found++, " "); //inserts " ", b/c insert --> punct pos moves 1
                if (found == text_.size()-1) return text_;//test for endOfstd::string
                if (text_[found+1] != ' ') text_.insert(found+1, " ");//inserts " " after punct only if not " " comes behind
                found = text_.find_first_of(".,;:-&", found+1);//finds next punct or symbol
        }
               
        //iter through the chars to convert to uppercase
        for (std::string::iterator it=text_.begin();it!=text_.end();++it)
                *it = toupper(*it);
        
        return text_;        
}
//creates set of unique words from text
set<std::string>& inputSet(set<std::string>& strSet_, char* filename)
{
        ifstream ifs;
        ifs.open(filename);
        if (ifs.fail()) {cout << "Input file opening failed.\n"; exit(1);}
       
        std::string word = "";
        unsigned int count = 0;
        for (;ifs >> word;++count)
                strSet_.insert(word);

        ifs.close();
        strSet_.insert("zzz"); //last input on the set

#ifdef _DEBUG        
        int countSet = 0;
        set<std::string>::iterator itStr;
        for (itStr = strSet_.begin();itStr != strSet_.end(); ++itStr, ++countSet)
                cout << countSet << ": " << *itStr << endl;
#endif        
        return strSet_;
}
//return word count, includes punctuation and symbols
//the text on the file should be massaged first
unsigned int wordCount(char* filename)
{
        ifstream ifs;
        ifs.open(filename);
        if (ifs.fail()) {cout << "Input file opening failed.\n"; exit(1);}
        
        std::string word = "";
        unsigned int count = 0;
        for (; ifs >> word; ++count);

        ifs.close();
        return count;
}
//returns posicion of word in the set, returns -1 if not found
int returnPos(set<std::string>& strSet_, std::string word)
{
        int pos_ = 0;
        set<std::string>::iterator it;
        for(it = strSet_.begin(); it != strSet_.end(); ++it, pos_++)
                if (*it == word) return pos_;
        return --pos_;  //--pos b/c loop reached the end
}
//returns pos of the bitset entry into bitset table
std::string decodeKey(set<std::string>& strSet_, bitset<10>* bitTable_, bitset<10> key)
{
        //find pos of a bitset code into the bitset table
        int pos = 0;
        for (;pos < strSet_.size(); pos++)
                if (key == bitTable_[pos]) break;
       
        //if bitset code was not found, possibly error when encoding text into bitset
        if (pos == strSet_.size()) 
        {
                cerr << "Bitset key from encoded text not found in bitset table. Program abort!.\n";
                exit(1);
        }

        //find word value at set position
        set<std::string>::iterator it = strSet_.begin();
        advance(it, pos);
        return *it;
}
int main()
{
        //get text from file 
        std::string text = getText("declaration.txt");
#ifdef _DEBUG        
        cout << text << endl;
        cin.get();
#endif        
        
        //massage text
        text = massageText(text);
#ifdef _DEBUG        
        cout << text << endl;
        cin.get();
#endif        

        //write massaged text to a temp file 
        ofstream ofs;
        ofs.open("declaration_ready.txt");
        ofs << text;
        ofs.close();
        
        //output word count of declaration_ready file
        cout << "Declaration words-punctuation-symbols count: " 
                << wordCount("declaration_ready.txt") << endl; 
       
        //create set of unique words
        set<std::string> strSet;
        strSet = inputSet(strSet, "declaration_ready.txt");
#ifdef _DEBUG        
        cout << "set completed\n";
        cin.get();
#endif        

        //create bitset table 
        bitset<10> bitTable[strSet.size()]; //strSet.size() amount entries on set
        //fill array with unique bitset values for each unique word on the set
        for (int i = 0; i < strSet.size(); i++)
                bitTable[i] = bitset<10>(i);

#ifdef _DEBUG        
        cout << "After returned from filllKeys\n";
        cin.get();
#endif       

/**************************   SECOND PART    *************************************
 * Get the gettysburg speech text
 * Massage the text
 * Put int on a file
 * Count words-punct-symbols
 * Encode gettysburg massage text into a bitsets corresponding with encoding performed before with declaration speech text.
 * Decode gettysburg speech from its encoded array of bitsets 
 ***********************************************************************************/
        
        //get "gettysburg.txt" into std::string 
        std::string gettyText = getText("gettysburg.txt");
#ifdef _DEBUG
        cout << gettyText << endl;
        cin.get();
#endif       
        //massage gettyText
        gettyText = massageText(gettyText);
#ifdef _DEBUG        
        cout << gettyText << endl;
        cin.get();
#endif 
        //write getty massaged text into a file
        ofstream ofs_getty;
        ofs_getty.open("gettysburg_ready.txt");
        ofs_getty << gettyText;
        ofs_getty.close();

        //output word count of declaration_ready file
        cout << "Gettysburg words-punctuation-symbols count: " 
                << wordCount("gettysburg_ready.txt") << endl; 

        //create bitset array for getty with values from original bitset array
        //create bitset<10> array of the size of the wordcount of text
        int getty_count = wordCount("gettysburg_ready.txt");//count words,puctuations & symbols
        bitset<10> arrayG[getty_count]; //gettysburg speech encoded bitset values
        
#ifdef _DEBUG        
        //test returnPos
        cout << "returnPos(strSet, ""TTHE""): " << returnPos(strSet, "TTHE") << endl;
        cin.get();
#endif        
        //iterate through words
        ifstream ifsG;
        ifsG.open("gettysburg_ready.txt");
        std::string w; 
        int pos = 0;  //pos of a word in the set
 
        //encodes new text with bitset table from original text
        for (int count = 0; ifsG >> w; count++)
        {
                //create function that returns pos of a word on original set
                //word not found returns last pos on set
                pos = returnPos(strSet, w);
                //assign the bitset value to arrayG[count] = array[pos] 
                arrayG[count] = bitTable[pos];
#ifdef _DEBUG
                cout<<"word:"<<w<<" pos:"<<pos<<" bitset: "
                    <<count<<": "<<arrayG[count]<<endl; 
                //cin.get();
#endif
        }
        ifsG.close();

        //decode gettysburg encoded bitset array to text
        std::string str = "";
        for (int i = 0; i < sizeof arrayG/sizeof arrayG[0]; i++)
                cout << decodeKey( strSet, bitTable, arrayG[i]) << " ";
        
        cout << endl;
        
        return 0;
}
