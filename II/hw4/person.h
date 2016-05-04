/*************************************************************
 file: person.h
synopsis: This is an interface for the class person
        primarily intended to be used as a base class to derive
        class patient.
***************************************************************/
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using std::string;

class Person
{
        public:
                Person();
                Person(string theName);
                Person(const Person& theObject);
                string getName() const;
                Person& operator=(const Person& rtSide);
                friend istream& operator >>(istream& inStream,
                                Person& personObject);
                friend ostream& operator <<(ostream& outStream,
                                const Person& personObject);
        private:
                string name;
};
#endif //PERSON_H
                
