#pragma once
#include <cstdio>
#include <iostream>

template<class T>
class Stack
{
public:
	Stack();
	Stack(const Stack& stack_cop);
	Stack(Stack&& stack_move) noexcept;
	Stack& operator=(Stack&& stack_move) noexcept;
	Stack& operator=(const Stack& stack_cop);

	bool operator==(const Stack& stack_cop) const noexcept;
	bool operator!=(const Stack& stack_cop);
	void operator<<(const T& elem);
	void operator>>(const T& elem);

	template <typename T> friend  std::ostream& operator<< (std::ostream&, const Stack<T>&) noexcept;

	Stack(int capacity);
	~Stack();

	void push(const T value);
	T pop();
	T check_pop();

	int getSize() const noexcept;
	void clear() noexcept;
	bool empty() const noexcept;
	void top(const T elem);
	void swap(T& elem);


	void printArray() const noexcept;
private:
	int size;
	int capacity;
	T* stack;
};

template <typename T> std::ostream& operator<< (std::ostream& os, const Stack<T>& st) noexcept {
	st.printArray();
	return os;
}