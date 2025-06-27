#pragma once
class Set {
private:
	static const int MAXSIZE = 10;
	static int N;
	int val[MAXSIZE] = { -1 };
	int size;
	char tag;
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
	Set operator ~();
	int getSize() const { return size; }
};