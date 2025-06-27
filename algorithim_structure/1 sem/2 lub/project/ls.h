#pragma once
#include <iostream>
#include <stdlib.h>

class Elem {
private:
	int i;
	Elem* next;
public:
	Elem(int number);
	~Elem() { delete next; };
	friend class Set;
};

class Set {
private:
	static const int MAXSIZE = 10;
	static int N;
	int size;
	Elem* first;
	char tag;
public:
	Set();
	Set(char ch);
	Set(const Set&);
	Set(Set&& B);
	~Set();
	void print();
	void add(int x);
	Set operator |= (const Set& B);
	Set operator | (const Set& B) const;
	Set operator &= (const Set& B);
	Set operator & (const Set& B)const;
	Set operator~ () const;
	void swap(Set& other) { std::swap(first, other.first); std::swap(size, other.size); }
	int getSize() { return size; }
};