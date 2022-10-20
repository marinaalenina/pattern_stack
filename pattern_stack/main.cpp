#include <iostream>
#include <time.h>
#include <stack>
#include "Stack.cpp"

using namespace std;

typedef struct st {
	int i;
	char* ch;
} st;

int main()
{
	//-------------------------------------- copied
	Stack<int> s;
	cout << "print stack 's':" << endl;
	s.printArray();
	Stack<int> s1(s);
	cout << "print stack 's1':" << endl;
	s1.printArray();

	try {
		cout << "check_pop stack 's':\t" << s.check_pop() << endl;
		cout << "print stack 's':" << endl;
		s.printArray();
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
	// copied = 
	Stack<int> s2 = s;
	cout << "cout stack 's2':" << endl;
	cout << s2;

	//-------------------------------------- moved
	Stack<double> s3;
	s3.push(5.5);
	s3.push(7.7);
	cout << "print stack 's3':" << endl;
	s3.printArray();
	Stack<double> s4(std::move(s3));
	cout << "print stack 's3':" << endl;
	s3.printArray();
	cout << "print stack 's4':" << endl;
	s4.printArray();
	// moved = 
	Stack<double> s5 = std::move(s4);
	cout << "print stack 's4':" << endl;
	s4.printArray();
	cout << "print stack 's5':" << endl;
	s5.printArray();

	// pop
	cout << "check_pop stck 's5':" << endl;
	cout << s5.check_pop() << endl;
	cout << "pop stack 's5':" << endl;
	cout << s5.pop() << endl;
	cout << "Array stack 's5':" << endl;
	s5.printArray();

	// size
	cout << "size stack 's5':" << endl;
	cout << s5.getSize() << endl;

	// clear
	cout << "clear stack 's5':" << endl;
	s5.clear();
	s5.printArray();

	// == !=
	Stack<char*> s6;
	char* str = (char*)"one";
	s6.push(str);

	Stack<char*> s7;
	s7.push((char*)"one");

	cout << "print stack 's6':" << endl;
	s6.printArray();
	cout << "print stack 's7':" << endl;
	s7.printArray();
	cout << "s6 == s7 ?:\t";
	cout << (s6 == s7) << endl;

	s7.push((char*)"two");
	cout << "print stack 's6':" << endl;
	s6.printArray();
	cout << "print stack 's7':" << endl;
	s7.printArray();

	cout << "s6 != s7 ?:\t";
	cout << (s6 != s7) << endl;

	// struct 
	Stack<st> s8;
	st st1 = { 5, (char*)"struct str" };
	s8.push(st1);

	cout << "check_pop stack 's8':" << endl;
	cout << s8.check_pop().i << endl;
	cout << s8.check_pop().ch << endl;

	// << >> вывод <<
	Stack<int> s9;
	cout << "check << >> " << endl;
	s9 << 8;
	cout << "print stack 's9':" << endl;
	s9.printArray();
	s9 >> 8;
	try {
		s9.pop();
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	try {
		s9.top(15);
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	try {
		int temp = 1;
		s9.swap(temp);
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	cout << "stack 's9' is empty?" << s9.empty() << endl;
	cout << "check top" << endl;
	s9 << 8;
	s9.top(15);
	cout << "print stack 's9':" << endl;
	s9.printArray();
	cout << "check swap" << endl;
	int temp = 89;
	s9.swap(temp);
	cout << "print stack 's9':" << endl;
	s9.printArray();
	cout << temp << endl;
	// check resize stack
	Stack<int> s10;
	s10 << 1;
	s10 << 1;
	s10 << 1;
	s10 << 1;
	s10 << 1;
	s10 << 1;
	s10 << 1;
	s10 << 1;
	// must do realloc
	s10 << 2;
	s10 << 2;
	s10 << 2;
	cout << "print stack 's10':" << endl;
	s10.printArray();

	cout << "pop:" << endl;
	cout << "System func:";
	stack<int> sti;

	clock_t tStart = clock();
	for (int i = 0; i < 10000000; i++)
		sti.push(i);


	printf("\ttime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	cout << "My func:";
	Stack<int> st11;

	tStart = clock();

	for (int i = 0; i < 10000000; i++)
		st11.push(i);

	printf("\ttime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	cout << "clear:" << endl;
	cout << "System func:";

	tStart = clock();


	printf("\ttime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	cout << "My func:";


	tStart = clock();

	printf("\ttime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	return 0;
}