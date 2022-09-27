#include <iostream>
#include "Stack.h"
#include <iomanip>
#include <initializer_list>

using namespace std;



// конструктор
template <typename T>
Stack<T>::Stack() {
    head = nullptr;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack& stack) {
    head = stack;
}

// конструктор перемещения
template <typename T>
Stack<T>::Stack(const Stack&& stack) {
    head = stack;
}

// конструктор со списком
template <typename T>
Stack<T>::Stack(initializer_list<T> list) {
    head = stack;
}

// деструктор
template <typename T>
Stack<T>::~Stack() {
    delete head;
}

// добавление элемента в стек
template <typename T>
bool Stack<T>::push(const T value) {
    Elem<T>* el;
    el->x = value;
    el->next = head;
    head = el;
    return true; // успешное выполнение операции
}

// изъятие верхнего элемента стека
template <typename T>
T Stack<T>::pop() {
    if (empty())
        throw length_error("stack is empty!"); // стек пуст

    head->x = head->next.x;
    head->next = head->next.next;

    return head->x; // успешное выполнение операции
}

// возвращает верхний элемент стека, без изъятия
template <typename T>
const T& Stack<T>::check_pop() const {
    if (empty())
        throw length_error("stack is empty!"); // стек пуст
    return head->x; // успешное выполнение операции
}

// очистка стека
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

// пусто?
template <typename T>
bool Stack<T>::empty() {
    return head == nullptr;
}

// размер стека
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

