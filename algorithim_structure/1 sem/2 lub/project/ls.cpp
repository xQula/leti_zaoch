#include "ls.h"

Elem::Elem(int number) :i(number), next(nullptr) {}

Set::~Set() {
	delete first;
}

void Set::add(int x) {
	if (first == nullptr) first = new Elem(x);
	else {
		Elem* cur = first;
		while (cur->next) cur = cur->next;
		cur->next = new Elem(x);
	}
}

Set::Set(Set&& B) : tag('A' + N++), size(B.size), first(B.first) {
	B.first = nullptr;
}

Set::Set() : tag('A' + N++), size(0), first(nullptr) {}

Set::Set(char ch) : tag('A' + N++), size(0), first(nullptr) {
	for (int i = 0; i < MAXSIZE; i++) if (rand() % 2 == 0) { add(i); size++; }
	print();
}

Set::Set(const Set& B) : tag('A' + N++), first(nullptr), size(0) {
	Elem* cur = B.first;
	while (cur) {
		add(cur->i); size++;
		cur = cur->next;
	}
}

Set Set::operator |= (const Set& B) {
	Set C(*this);
	for (Elem* cur = B.first; cur; cur = cur->next) {
		bool alreadyExist = 0;
		for (Elem* check = C.first; check; check = check->next) {
			if (cur->i == check->i) alreadyExist = 1;
		}
		if (!alreadyExist) { C.add(cur->i); C.size++; };
	}
	swap(C);
	return *this;
}
Set Set::operator | (const Set& B) const {
	Set C(*this);
	return C |= B;
}

Set Set::operator &= (const Set& B) {
	Set X;
	for (Elem* e = first; e; e = e->next) {
		for (Elem* j = B.first; j; j = j->next) {
			if (e->i == j->i) {
				X.add(e->i);
				X.size++;
			}
		}
	}
	swap(X);
	return *this;
}
Set Set::operator & (const Set& B) const {
	Set C(*this);
	return C &= B;
}

Set Set::operator~() const
{
	Set C;
	Elem* a = C.first;
	for (int c = 0; c <= 9; ++c) {
		bool f = true;
		for (Elem* e = first; e; e = e->next) {
			if (c == e->i) { f = false; break; }
		}
		if (f) {
			C.add(c);
			++C.size;
		}
	}
	return C;
}

void Set::print() {
	std::cout << tag << ": ";
	if (first == nullptr) std::cout << "[EMPTY]" << std::endl;
	else {
		Elem* cur = first;
		while (cur) {
			std::cout << cur->i;
			cur = cur->next;
		}
	}
	std::cout << std::endl;
}