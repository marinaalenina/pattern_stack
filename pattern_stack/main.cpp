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
    int size; // ������ �����
    Elem<T>* head; // ������� �����
public:
    Stack();// ����������� �� ���������
    Stack(const Stack& stack);// ����������� �����������
    ~Stack(); // ����������
    bool push(const T); // ��������� ������� � ����
    bool pop(); // ������� �� ����� �������
    void clear();
    int size();
};

//int main()
//{
//    Stack <int> myStack(5);
//
//    // ��������� ����
//    cout << "����������� �������� � ����: ";
//    int ct = 0;
//    while (ct++ != 5)
//    {
//        int temp;
//        cin >> temp;
//        myStack.push(temp);
//    }
//
//    myStack.printStack(); // ����� ����� �� �����
//
//    cout << "\n������� ��� �������� �� �����:\n";
//
//    myStack.pop(); // ������� ������� �� �����
//    myStack.pop(); // ������� ������� �� �����
//    myStack.printStack(); // ����� ����� �� �����
//
//    return 0;
//}

// �����������
template <typename T>
Stack<T>::Stack() {
    size = 0;   // ���������������� ������ �����
    head = nullptr; // c��� ����
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack& stack) {
    size = 0;   // ���������������� ������ �����
    head = nullptr; // c��� ����
}

// ����������
template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr; // ������� ����
}

// ������� ������� ������  Stack ��� ��������� �������� � ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ������� � ���� �� ��������
template <typename T>
bool Stack<T>::push(const T value) {
    if (top   == size - 1)
        return false; // ���� �����

    top++;
    stackPtr[top] = value; // �������� ������� � ����

    return true; // �������� ���������� ��������
}

// ������� ������� ������  Stack ��� �������� �������� �� ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ���� ����
template <typename T>
bool Stack<T>::pop()
{
    if (top == -1)
        return false; // ���� ����

    stackPtr[top] = 0; // ������� ������� �� �����
    top--;

    return true; // �������� ���������� ��������
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