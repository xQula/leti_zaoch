#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <chrono>
//#include "arr.h"
//#include "bool_vec.h"
//#include "machine_word.h"
//#include "ls.h"

using namespace std;

int Set::N = 0;
int main()
{
	auto m1 = chrono::steady_clock::now();
	const long TIMER = 1000000;
	srand(time(nullptr));
	{
		Set A('A');
		Set B('B');
		Set C('C');
		Set D('D');
		Set E(A & ~(B & C) & ~D);
		E.print();
		cout << "Middle avg: " << (A.getSize() + B.getSize() + C.getSize() + D.getSize()) / 4 << endl;
	}
	auto m2 = chrono::steady_clock::now();
	auto delta1 = chrono::steady_clock::duration(m2 - m1);
	cout << "TIME: " << delta1.count() << " of " << TIMER << endl;
	cin.get();
	return 0;

}