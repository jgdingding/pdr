#ifndef INTCELL_H
#define INTCELL_H

class IntCell{
	public:
		IntCell(int initialValue = 0); //constructor, has a default value for parameter

		int getValue() const; //const means won't modify any fields
		void setValue(int val);

	private:
		int storedValue;
		int max(int m) const;

};
#endif
