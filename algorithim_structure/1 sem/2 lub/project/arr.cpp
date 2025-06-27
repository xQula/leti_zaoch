#include <iostream>
#include <clocale>
#include <cstdlib>
#include <list>
#include <ctime>
#include <chrono>
#include "arr.h"
Set::~Set() = default;

Set::Set() : tag('E' + N++), size(0) {}

Set::Set(char ch) : tag('A' + N++), size(0) {
	for (int i = 0; i < MAXSIZE; i++) if (rand() % 7 == 0) val[size++] = i;
	print();
}

Set::Set(const Set& B) : tag('A' + N++), size(B.size) {
	for (int i = 0; i < MAXSIZE; i++) val[i] = B.val[i];
}

Set Set::operator |= (const Set& B) {
	bool alreadyExist = 0;
	for (int i = 0; i < B.size; i++) {
		for (int j = 0; j < size; j++) {
			if (B.val[i] == val[j]) alreadyExist = 1;
		}
		if (!alreadyExist) val[size++] = B.val[i];
	}
	return *this;
}
Set Set::operator | (const Set& B) {
	Set C(*this);
	return C |= B;
}

Set Set::operator &= (const Set& B) {
	for (int i = 0; i < size; i++) {
		bool isCorrect = 0;
		for (int j = 0; j < B.size; j++) {
			if (val[i] == B.val[j]) isCorrect = 1;
		}
		if (!isCorrect) {
			for (int k = i; k < size - 1; k++) val[k] = val[k + 1];
			size--;
		}
	}
	return *this;
}
Set Set::operator & (const Set& B) {
	Set C(*this);
	return C &= B;
}

void Set::print() {
	std::cout << tag << ": ";
	for (int i = 0; i < size; i++) std::cout << val[i];
	std::cout << std::endl;
}

Set Set::operator~()
{
	Set C;
	for (int c = 0; c <= 9; ++c) {
		bool f = true;
		for (int j = 0; j < size; ++j) {
			if (c == val[j]) { f = false; break; }
		}
		if (f) C.val[C.size++] = c;
	}
	return C;
}
