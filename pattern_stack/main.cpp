#include <iostream>

using namespace std;

#include <iomanip>

template <typename T>
struct Elem {
public:
    T x;
    Elem next;
};

template <typename T>
class Stack {
private:
    int size; // размер стека
    Elem<T>* head; // вершина стека
public:
    Stack();// конструктор по умолчанию
    Stack(const Stack& stack);// конструктор копирования
    ~Stack(); // деструктор
    bool push(const T); // поместить элемент в стек
    bool pop(); // удалить из стека элемент
    void clear();
    int size();
};

//int main()
//{
//    Stack <int> myStack(5);
//
//    // заполняем стек
//    cout << "Заталкиваем элементы в стек: ";
//    int ct = 0;
//    while (ct++ != 5)
//    {
//        int temp;
//        cin >> temp;
//        myStack.push(temp);
//    }
//
//    myStack.printStack(); // вывод стека на экран
//
//    cout << "\nУдаляем два элемента из стека:\n";
//
//    myStack.pop(); // удаляем элемент из стека
//    myStack.pop(); // удаляем элемент из стека
//    myStack.printStack(); // вывод стека на экран
//
//    return 0;
//}

// конструктор
template <typename T>
Stack<T>::Stack() {
    size = 0;   // инициализировать размер стека
    head = nullptr; // cтек пуст
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack& stack) {
    size = 0;   // инициализировать размер стека
    head = nullptr; // cтек пуст
}

// деструктор
template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr; // удаляем стек
}

// элемент функция класса  Stack для помещения элемента в стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, элемент в стек не добавлен
template <typename T>
bool Stack<T>::push(const T value) {
    if (top   == size - 1)
        return false; // стек полон

    top++;
    stackPtr[top] = value; // помещаем элемент в стек

    return true; // успешное выполнение операции
}

// элемент функция класса  Stack для удаления элемента из стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, стек пуст
template <typename T>
bool Stack<T>::pop()
{
    if (top == -1)
        return false; // стек пуст

    stackPtr[top] = 0; // удаляем элемент из стека
    top--;

    return true; // успешное выполнение операции
}

template <typename T>
void Stack<T>::clear() {
    Elem* st, copy;
    st = head;
    while (st != nullptr) {
        copy = st->next;
        delete st;
    }
}

template <typename T>
int Stack<T>::size() {
    return size;
}