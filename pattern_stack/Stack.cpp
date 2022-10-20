#include "Stack.h"

template<class T>
Stack<T>::Stack(void)
{
	this->size = 0;
	this->capacity = 8;
	this->stack = (T*)calloc(capacity, sizeof(T));

	if (stack == nullptr)
		throw std::invalid_argument("Memory error");

	std::cout << "Created" << std::endl;
}

template<class T>
Stack<T>::~Stack()
{
	printf("Destroyed\n");
	free(stack);
}

template<class T>
Stack<T>::Stack(const Stack& stack_cop)
{
	std::cout << "copied" << std::endl;
	this->size = stack_cop.size;
	this->capacity = stack_cop.capacity;
	this->stack = (T*)calloc(capacity, sizeof(T));

	if (stack == nullptr)
		throw std::invalid_argument("Memory error");


	memcpy(stack, stack_cop.stack, sizeof(T) * size);
}

template<class T>
Stack<T>::Stack(Stack&& stack_move) noexcept
{
	std::cout << "moved" << std::endl;

	this->size = stack_move.size;
	this->capacity = stack_move.capacity;
	this->stack = stack_move.stack;

	stack_move.stack = nullptr;
	stack_move.size = 0;
	stack_move.capacity = 0;

}

template<class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& stack_move) noexcept
{
	std::cout << "moved" << std::endl;

	if (this != &stack_move) {
		free(stack);

		this->size = stack_move.size;
		this->capacity = stack_move.capacity;
		this->stack = stack_move.stack;

		stack_move.stack = nullptr;
		stack_move.size = 0;
		stack_move.capacity = 0;
	}

	return *this;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack_cop)
{
	std::cout << "copied" << std::endl;

	if (this != &stack_cop) {
		free(stack);

		this->size = stack_cop.size;
		this->capacity = stack_cop.capacity;
		this->stack = (T*)calloc(capacity, sizeof(T));

		if (stack == nullptr)
			throw std::invalid_argument("Memory error");

		memcpy(stack, stack_cop.stack, sizeof(T) * size);
	}

	return *this;
}

template<class T>
bool Stack<T>::operator==(const Stack<T>& s) const noexcept
{
	if (this->size != s.size) return false;
	for (int i = 0; i < size; i++)
		if (this->stack[i] != s.stack[i])
			return false;
	return true;
}

template<class T>
bool Stack<T>::operator!=(const Stack<T>& s)
{
	return !(*this == s);
}

template<class T>
void Stack<T>::operator<<(const T& elem)
{
	this->push(elem);
}


template<class T>
void Stack<T>::operator>>(const T& elem)
{
	if (check_pop() == elem) {
		pop();
		return;
	}

	throw std::invalid_argument("This element is not top element");
}

template<class T>
Stack<T>::Stack(int capacity)
{
}

template<class T>
void Stack<T>::push(const T value)
{
	this->size++;
	if (size == capacity) {
		capacity *= 2;
		stack = (T*)realloc(stack, capacity * sizeof(T));
		if (stack == nullptr)
			throw std::invalid_argument("Memory error");
	}

	stack[size - 1] = value;
}

template<class T>
void Stack<T>::printArray() const noexcept
{
	for (int i = 0; i < size; i++)
		std::cout << stack[i] << std::endl;
	std::cout << std::endl;
}

template<class T>
T Stack<T>::pop()
{
	if (size == 0) {
		throw std::invalid_argument("Illegal operation. Cannot pop zero size stack");
	}

	else {
		this->size--;
		T res = stack[size];
		stack[size] = 0;
		return res;
	}
}

template<class T>
T Stack<T>::check_pop()
{
	if (size == 0)
		throw std::invalid_argument("Illegal operation. Cannot pop zero size stack");
	return stack[size - 1];
}

template<class T>
bool Stack<T>::empty() const noexcept
{
	return size == 0;
}

template<class T>
void Stack<T>::clear() noexcept
{
	if (empty()) return;
	size = 0;
	memset(stack, 0, sizeof(T) * capacity);
}

template<class T>
int Stack<T>::getSize() const noexcept
{
	return this->size;
}

template<class T>
void Stack<T>::swap(T& elem)
{
	if (size == 0)
		throw std::invalid_argument("Illegal operation. Cannot swap zero size stack");

	int temp = stack[size - 1];
	stack[size - 1] = elem;
	elem = temp;
}

template<class T>
void Stack<T>::top(const T elem)
{
	if (size == 0) {
		throw std::invalid_argument("Illegal operation. Cannot replace zero size stack");
		return;
	}
	stack[size - 1] = elem;
}

