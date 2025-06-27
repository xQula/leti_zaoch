#include <iostream>
#include <clocale>
#include <cstdlib>
#include "bool_vec.h"

using namespace std;

Set::Set() : tag('E' + N++), size(0) {
}

Set::Set(char ch) : tag('A' + N++), size(0) {
	for (int i = 0; i < MAXSIZE; i++) { val[i] = rand() % 2; size++; }
	print();
}

Set::Set(const Set& B) : tag('A' + N++), size(0) {
	for (int i = 0; i < MAXSIZE; i++) { val[i] = B.val[i]; size++; }
	//cout << "Set " << tag << " has been created!" << endl;
	//print();
}

Set Set::operator |= (const Set& B) {
	for (int i = 0; i < MAXSIZE; i++) {
		if (!val[i] && B.val[i]) size++;
		val[i] = val[i] | B.val[i];
	}
	return *this;
}
Set Set::operator | (const Set& B) {
	Set C(*this);
	return C |= B;
}

Set Set::operator &= (const Set& B) {
	for (int i = 0; i < MAXSIZE; i++) {
		if (val[i] && B.val[i]) size++;
		val[i] = val[i] & B.val[i];
	}
	return *this;
}
Set Set::operator & (const Set& B) {
	Set C(*this);
	return C &= B;
}

Set::~Set() {}

void Set::print() {
	cout << tag << ": ";
	for (int i = 0; i < MAXSIZE; i++) {
		if (val[i]) cout << i;
		else cout << 'x';
	}
	cout << endl;
}

Set Set::operator~() const
{
	Set C;
	for (int i = 0; i < size; ++i) {
		if (val[i] != true) {
			C.val[i] = true;
		}
	}
	return C;
}
