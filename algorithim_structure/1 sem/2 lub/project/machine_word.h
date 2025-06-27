#pragma once

class Set {
private:
	static const int MAXSIZE = 10;
	static int N;
	int val;
	char tag;
public:
	Set();
	Set(char ch);
	Set(const Set&);
	void print();

	Set operator |= (const Set& B);
	Set operator | (const Set& B);
	Set operator &= (const Set& B);
	Set operator & (const Set& B);
	Set operator~ () const ;
	int getSize() { return 10; }
};