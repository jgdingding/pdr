//Justin Gou
//jyg2qhc
//1/20/2020
//LifeCycle.h

#include <iostream>
#include <string>
#ifndef LIFECYCLE_H
#define LIFECYCLE_H
using namespace std;

class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif

