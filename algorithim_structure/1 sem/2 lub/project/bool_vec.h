#pragma once
class Set {
private:
	static const int MAXSIZE = 10;
	static int N;
	bool val[MAXSIZE] = { 0 };
	char tag;
	int size;
public:
	Set();
	Set(char ch);
	Set(const Set&);
	~Set();
	void print();

	Set operator |= (const Set& B);
	Set operator | (const Set& B);
	Set operator &= (const Set& B);
	Set operator & (const Set& B);
	Set operator~ () const;
	int getSize() { return size; }
};