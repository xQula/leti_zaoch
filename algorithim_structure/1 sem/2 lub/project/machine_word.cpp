#include <iostream>
#include <clocale>
#include <cstdlib>
#include "machine_word.h"

using namespace std;

Set::Set() : val(0), tag('E' + N++) {
	//cout << "Empty set " << tag << " has been created!" << endl;
}

Set::Set(char ch) : val(rand()), tag('A' + N++) {
	print();
}

Set::Set(const Set& B) : val(B.val), tag('A' + N++) {
	//cout << "Set " << tag << " has been created!" << endl;
	//print();
}

Set Set::operator |= (const Set& B) {
	val = val | B.val;
	return *this;
}
Set Set::operator | (const Set& B) {
	Set C(*this);
	return C |= B;
}

Set Set::operator &= (const Set& B) {
	val = val & B.val;
	return *this;
}
Set Set::operator & (const Set& B) {
	Set C(*this);
	return C &= B;
}

Set Set::operator~() const
{
	Set C;
	C.val -= (val + 1);
	return C;
}



void Set::print() {
	cout << tag << ": ";
	for (int i = MAXSIZE - 1; i >= 0; --i) {
		if (val & (1 << i))cout << i;
		else cout << 'x';
	}
	cout << endl;
}
