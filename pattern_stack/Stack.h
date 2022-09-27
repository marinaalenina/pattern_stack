#pragma once
#include <iostream>
#include <iomanip>
#include <initializer_list>

template <typename T>
struct Elem {
public:
    T x;
    Elem next;
};

template <typename T>
class Stack {
private:
    //int size; // ������ �����
    Elem<T>* head; // ������� �����
public:
    Stack();// ����������� �� ���������
    Stack(const Stack& stack);// ����������� �����������
    Stack(const Stack&& stack);// ����������� �����������
    Stack(initializer_list<T> list); // ����������� �� ������� �������������
    ~Stack(); // ����������
    bool push(const T); // ��������� ������� � ����
    T pop(); // ������ ������� �� �����
    const T& check_pop() const; // ����� �������� ��� ������� �� �����
    void clear(); // ������� �����
    bool empty(); // ������ ����?
    int size(); // ������ �����
    friend Stack<T> operator=(); // ����������� � �����������
    friend void operator<<(Stack& stack, T el); // ���������� ��������
    friend ostream& operator<<(ostream& out, const Stack& stack);
    friend void operator>>(T el); // ������� ��������
    friend bool operator==();
    friend bool operator!=();
};