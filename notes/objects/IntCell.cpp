#include "IntCell.h"
using namespace std;

IntCell::IntCell (int initialValue):
	storedValue(initialValue){} //fieldName(valueName) is one way to initiate a field, comma separated

int IntCell::getValue() const{
	return storedValue;
}

void IntCell :: setValue(int val){
	storedValue = val;
}

int IntCell :: max(int m) const {
	return (m>storedValue) ? m : storedValue;
}
