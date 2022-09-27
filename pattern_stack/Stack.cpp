#include <iostream>
#include "Stack.h"
#include <iomanip>
#include <initializer_list>

using namespace std;



// �����������
template <typename T>
Stack<T>::Stack() {
    head = nullptr;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack& stack) {
    head = stack;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack&& stack) {
    head = stack;
}

// ����������� �� �������
template <typename T>
Stack<T>::Stack(initializer_list<T> list) {
    head = stack;
}

// ����������
template <typename T>
Stack<T>::~Stack() {
    delete head;
}

// ���������� �������� � ����
template <typename T>
bool Stack<T>::push(const T value) {
    Elem<T>* el;
    el->x = value;
    el->next = head;
    head = el;
    return true; // �������� ���������� ��������
}

// ������� �������� �������� �����
template <typename T>
T Stack<T>::pop() {
    if (empty())
        throw length_error("stack is empty!"); // ���� ����

    head->x = head->next.x;
    head->next = head->next.next;

    return head->x; // �������� ���������� ��������
}

// ���������� ������� ������� �����, ��� �������
template <typename T>
const T& Stack<T>::check_pop() const {
    if (empty())
        throw length_error("stack is empty!"); // ���� ����
    return head->x; // �������� ���������� ��������
}

// ������� �����
template <typename T>
void Stack<T>::clear() {
    Elem* st, copy;
    st = head;
    while (st != nullptr) {
        copy = st->next;
        delete st;
    }
    head = nullptr;
}

// �����?
template <typename T>
bool Stack<T>::empty() {
    return head == nullptr;
}

// ������ �����
template <typename T>
int Stack<T>::size() {
    int size = 0;
    Elem<T>* el = head;
    while (el->next) {
        size++;
        el = el->next;
    }
    return size;
}

