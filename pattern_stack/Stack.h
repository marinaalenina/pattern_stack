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
    //int size; // размер стека
    Elem<T>* head; // вершина стека
public:
    Stack();// конструктор по умолчанию
    Stack(const Stack& stack);// конструктор копировани€
    Stack(const Stack&& stack);// конструктор перемещени€
    Stack(initializer_list<T> list); // конструктор со списком инициализации
    ~Stack(); // деструктор
    bool push(const T); // поместить элемент в стек
    T pop(); // изъ€ть элемент из стека
    const T& check_pop() const; // вызов элемента без изъ€тие из стека
    void clear(); // очистка стека
    bool empty(); // пустой стек?
    int size(); // размер стека
    friend Stack<T> operator=(); // перемещение и копирование
    friend void operator<<(Stack& stack, T el); // добавление элемента
    friend ostream& operator<<(ostream& out, const Stack& stack);
    friend void operator>>(T el); // изъ€тие элемента
    friend bool operator==();
    friend bool operator!=();
};