#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <random>
#include <time.h>
#include <thread>
#include <chrono>

//func f()
char anconverting_char(char var) {
	var += '0';
	return var;
}

char converting_char(char var) {
	var -= '0';
	return var;
}

// rundom number 
template <typename T>
T rundom_set() {
	T rundom_set;
	rundom_set.reserve(10);
	std::random_device rd1;
	std::mt19937 gen1{rd1()};
	std::uniform_int_distribution<> dis1(0, 9);
	int size = dis1(gen1);
	for (std::vector<char>::size_type i = 0; i < size; ++i) {
		rundom_set.emplace_back(anconverting_char(static_cast<char>(dis1(gen1))));
	}
	return rundom_set;
}

// array
std::vector<char> creat_b_conjunction_c_vec(
	const std::vector<char>& b, const std::vector<char>& c) 
{
	std::vector<char> var;
	for (const auto& i : b) {
		for (const auto& k : c) {
			if (i == k)
				var.emplace_back(i);
		}
	}
	return var;
}

void difference_sets_a_cb_vec(std::vector<char>& var, const std::vector<char>& other) {
	std::vector<char> vec{other};
	for (auto&& i : vec) {
		for (const auto& k : var) {
			if (i == k)
				i = '*';
		}
	}
	var = std::move(vec);
}

void difference_sets_a_d_vec(std::vector<char>& var, const std::vector<char>& other) {
	for (auto&& i : var) {
		for (const auto& k : other) {
			if (i == k)
				i = '*';
		}
	}
}

std::vector<char> creat_e_vec(
	const std::vector<char>& a, const std::vector<char>& b,
	const std::vector<char>& c, const std::vector<char>& d) 
{
	std::vector<char> var = creat_b_conjunction_c_vec(b, c);
	difference_sets_a_cb_vec(var, a);
	difference_sets_a_d_vec(var, d);
	std::vector<char> vec;
	vec.reserve(var.size());
	for (auto& i: var) {
		if (i != '*')
			vec.push_back(i);
	}
	return vec;
}

//bits
std::vector<char> anconvering_vec_bits(const std::vector<char> var, const int size) {
	std::vector<char> other(var.size(), 0);
	for (std::vector<char>::size_type i = 0, k = 0; i < size; ++i) {
		if (var[i]) {
			char a = anconverting_char(i);
			other[k++] = a;
		}
	}
	return other;
}

std::vector<char> converting_vec_bits(const std::vector<char> var) {
	std::vector<char> bit_var(10, 0);
	for (std::vector<char>::size_type i = 0; i < var.size(); ++i) {
		bit_var[converting_char(var[i])] = 1;
	}
	return bit_var;
}

std::vector<char> creat_b_bit_conjunction_c_bit(
	const std::vector<char> &b, const std::vector<char> &c)
{
	std::vector<char> var(b.size(), 0);
	for (std::vector<char>::size_type i = 1; i < b.size(); ++i) {
		if (b[i] && c[i])
			var[i] = 1;
	}
	return var;
}

std::vector<char> difference_sets_bit(const std::vector<char>& var, const std::vector<char>& other) {
	std::vector<char> vec_a(var.size(), 0);
	for (std::vector<char>::size_type i = 0; i < var.size(); ++i) {
		if (other[i] && !var[i])
			vec_a[i] = 1;
	}
	return vec_a;
}

std::vector<char> creat_e_vec_bit(
	const std::vector<char>& a, const std::vector<char>& b,
	const std::vector<char>& c, const std::vector<char>& d) 
{
	std::vector<char> var = creat_b_bit_conjunction_c_bit(b, c);
	var = difference_sets_bit(var, a);
	var = difference_sets_bit(d, var);
	return var;
}

//words
short int converting_vec_word_machine(const std::vector<char>& var) {
	short int w_var = 0;
	for (std::vector<char>::size_type i = 0; i < var.size(); ++i) {
		w_var |= (1 << (static_cast<int>(converting_char(var[i]))));
	}
	return w_var;
}

std::vector<char> anconverting_vec_word_machine(const short int var,const int size) {
	std::vector<char> other;
	for (std::vector<char>::size_type i = 0; i <= size; i++) {
		if ((var >> i) & 1)
			other.push_back(anconverting_char(i));
	}
	return other;
}

short int creat_e_word( short int a, const short int& b, 
	const short int c, const short int& d)
{ 
	short int e = { a & ~(b & c) & ~d };
	return e;
}

//list

std::list<char> creat_list(const std::vector<char>& a) {
	std::list<char> var;
	for (const auto& i : a) {
		var.push_back(i);
	}
	return var;
}

std::list<char> creat_b_conjunction_c_list(const std::list<char>& b, const std::list<char>& c) {
	std::list<char> var;
	for (const auto& i : b) {
		for (const auto& k : c) {
			if (i == k)
				var.push_back(i);
		}
	}
	return var;
}

void difference_sets_a_cb_list(std::list<char>& var, const std::list<char>& other) {
	std::list<char> ls {other};
	for (auto&& i : ls) {
		for (const auto& k : var) {
			if (i == k)
				i = '*';
		}
	}
	var = std::move(ls);
}

void difference_sets_a_d_list(std::list<char>& var, const std::list<char>& other) {
	for (auto&& i : var) {
		for (const auto& k : other) {
			if (i == k)
				i = '*';
		}
	}
}

std::list<char> creat_e_list(const std::list<char>& a, const std::list<char>& b,
	const std::list<char>& c, const std::list<char>& d) 
{
	std::list<char> var = creat_b_conjunction_c_list(b, c);
	difference_sets_a_cb_list(var, a);
	difference_sets_a_d_list(var, d);
	std::list<char> ls;
	for (auto& i : var) {
		if (i != '*')
			ls.push_back(i);
	}
	return ls;

}

//out
template <typename T>
void out(const T& a, const char& name) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << name << ": ";
	for (const auto& i : a) {
		if (i == '\x1')
			std::cout << anconverting_char(i) << ' ';
		else
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

template <typename T>
void out_vecs_time(const T& a, const T& b,
	const T& c, T& d,
	const T& e, const std::chrono::duration<double, std::milli> &res_time)
{
	out(a, 'A');
	out(b, 'B');
	out(c, 'C');
	out(d, 'D');
	out(e, 'E');
	std::cout << "Time: " << res_time.count() << " milli" << std::endl;
}

void out_vecs(const std::vector<char>& a, const std::vector<char>& b,
	const std::vector<char>& c, const std::vector<char>& d,
	const std::vector<char>& e)
{
	out(a, 'A');
	out(b, 'B');
	out(c, 'C');
	out(d, 'D');
	out(e, 'E');
}

void out_word(short int a, short int b, short int c, short int d, short int e,
	const std::chrono::duration<double, std::milli> &res_time) 
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "A: " << a << std::endl <<
		"B: " << b << std::endl <<
		"C: " << c << std::endl <<
		"D: " << d << std::endl <<
		"E: " << e << std::endl;
	std::cout << "Time: " << res_time.count() << " milli" << std::endl;
}

//interface

std::vector<char> in_vec() {
	std::vector<char> var;
	int size = 10;
	char ch = 0;
	std::cout << "Enter: ";
	for (std::vector<char>::size_type i = 0; i < size; ++i) {
		std::cout << "-> ";
		std::cin >> ch;
		if (ch == 'b')
			break;
		if (ch == 'e') {
			var.reserve(10);
			break;
		}
		var.push_back(ch);
	}
	return var;
}

void interface_vec(std::vector<char>& a, std::vector<char>& b,
	std::vector<char>& c, std::vector<char>& d, int choice)
{
	if (choice == 1) {
		// standart
		a = { '1','2','3','4','5','6','7','8','9' };
		b = { '1','2' };
		c = { '2','3' };
		d = { '3' };
	}else if(choice == 2){
		// random
		a = rundom_set<std::vector<char>>();
		b = rundom_set<std::vector<char>>();
		c = rundom_set<std::vector<char>>();
		d = rundom_set<std::vector<char>>();
	}
	else if (choice == 3) {
		std::cout << "A: ";
		a = in_vec();
		std::cout << "B: ";
		b = in_vec();
		std::cout << "C: ";
		c = in_vec();
		std::cout << "D: ";
		d = in_vec();
	}
}

// Вариант 17, E = A - (B * C) - D
int main()
{
	int size = 10;
	// array
	std::cout << std::endl << "Array" << std::endl;
	std::vector<char> A;
	std::vector<char> B;
	std::vector<char> C;
	std::vector<char> D;
	// choice 1 - standart; 2 - rand; 3 - cin;
	interface_vec(A, B, C, D, 2);
	auto time_start1 = std::chrono::high_resolution_clock::now();
	std::vector<char> E = creat_e_vec(A,B,C,D);
	auto time_end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> res_time1 = time_end1 - time_start1;
	out_vecs_time(A, B, C, D, E, res_time1);

	//bits
	std::cout << std::endl << "Bits" << std::endl;
	auto time_start2 = std::chrono::high_resolution_clock::now();
	std::vector<char> bit_a = converting_vec_bits(A);
	std::vector<char> bit_b = converting_vec_bits(B);
	std::vector<char> bit_c = converting_vec_bits(C);
	std::vector<char> bit_d = converting_vec_bits(D);
	std::vector<char> bit_e = creat_e_vec_bit(bit_a, bit_b, bit_c, bit_d);
	std::vector<char> reverse_bit_E = anconvering_vec_bits(bit_e, size);
	auto time_end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> res_time2 = time_end2 - time_start2;
	out_vecs_time(bit_a, bit_b, bit_c, bit_d, bit_e, res_time2);

	std::cout << std::endl << "Reverse_bits" << std::endl;
	std::vector<char> reverse_bit_A = anconvering_vec_bits(bit_a, size);
	std::vector<char> reverse_bit_B = anconvering_vec_bits(bit_b, size);
	std::vector<char> reverse_bit_C = anconvering_vec_bits(bit_c, size);
	std::vector<char> reverse_bit_D = anconvering_vec_bits(bit_d, size);
	
	out_vecs(reverse_bit_A, reverse_bit_B, reverse_bit_C, reverse_bit_D, reverse_bit_E);

	//words
	std::cout << std::endl << "Word" << std::endl;
	auto  time_start3 = std::chrono::high_resolution_clock::now();
	short int word_a = converting_vec_word_machine(A);
	short int word_b = converting_vec_word_machine(B);
	short int word_c = converting_vec_word_machine(C);
	short int word_d = converting_vec_word_machine(D);
	short int word_z = ~word_c;
	short int word_e = creat_e_word(word_a, word_b, word_c, word_d);
	auto time_end3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> res_time3 = time_end3 - time_start3;
	out_word(word_a, word_b, word_c, word_d, word_e, res_time3);

	std::cout << std::endl << "Reverse_word" << std::endl;
	std::vector<char> reverse_word_A = anconverting_vec_word_machine(word_a, size);
	std::vector<char> reverse_word_B = anconverting_vec_word_machine(word_b, size);
	std::vector<char> reverse_word_C = anconverting_vec_word_machine(word_c, size);
	std::vector<char> reverse_word_D = anconverting_vec_word_machine(word_d, size);
	std::vector<char> reverse_word_E = anconverting_vec_word_machine(word_e, size);
	out_vecs(reverse_word_A, reverse_word_B, reverse_word_C, reverse_word_D, reverse_word_E);

	//list
	std::cout << std::endl << "List" << std::endl;
	auto  time_start4 = std::chrono::high_resolution_clock::now();
	std::list<char> list_a = creat_list(A);
	std::list<char> list_b = creat_list(B);
	std::list<char> list_c = creat_list(C);
	std::list<char> list_d = creat_list(D);
	std::list<char> list_e = creat_e_list(list_a, list_b, list_c, list_d);
	auto time_end4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> res_time4 = time_end4 - time_start4;
	out_vecs_time(list_a, list_b, list_c, list_d, list_e, res_time4);
	
}

