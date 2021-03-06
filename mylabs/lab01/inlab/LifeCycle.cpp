//Justin Gou
//jyg2qhc
//1/20/2020
//LifeCycle.cpp

#include <iostream>
#include <string>
#include "LifeCycle.h"
using namespace std;

MyObject::MyObject() {
    // Important: notice how we don't define 'name' or 'id' here
    // Instead, we're setting the variables that we declared in MyObject
    name = "--default--";
    id = ++numObjs;
    cout << "MyObject Default constructor:   " << *this << endl;
}

MyObject::MyObject(string n) {
    name = n;
    id = ++numObjs;
    cout << "MyObject Parameter constructor: " << *this << endl;
}

MyObject::MyObject(const MyObject& rhs) {
    name = rhs.name;
    id = ++numObjs;
    cout << "MyObject Copy constructor:      " << *this << endl;
}

MyObject::~MyObject() {
    cout << "MyObject Destructor:            " << *this << endl;
}

// Regular methods, with return types
string MyObject::getName() const {
    return name;
}

void MyObject::setName(const string& newName) {
    name = newName;
}


