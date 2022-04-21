#include <iostream>

#include <vector>

template < typename T > class Stack;
template < typename T > std::ostream& operator << (std::ostream& out,
    const Stack < T >& stack);

template < typename T >
class Stack {

public:
    Stack(size_t size = 10);
    ~Stack();
    T pop();
    void push(const T& value);
    T* getContainer();
    bool isEmpty();
    friend std::ostream& operator << < > (std::ostream& out,
        const Stack& stack);
    size_t getCurrentSize();

private:
    T* m_container;
    size_t m_size;
    size_t m_index;


};

template < class T >
Stack < T > ::Stack(size_t size) {
    std::cout << "Stack constructor\n";
    m_container = new T[size];
    m_size = size;
    m_index = 0;

}
template < typename T >
T Stack < T > ::pop() {
    std::cout << "Stack pop \n";
    if (m_index <= 0)
        exit(0);

    return  m_container[--m_index];

}

template < typename T >
void Stack < T > ::push(const T& value) {
    std::cout << "Stack push\n";
    if (m_index >= m_size)
        exit(0);
    m_container[m_index++] = value;


}
template < typename T >
T* Stack < T > ::getContainer() {
    return  m_container;
}

template < typename T >
bool Stack < T > ::isEmpty() {
    return m_index == 0;
}

template < typename T >
std::ostream& operator << (std::ostream& out,
    const Stack < T >& stack) {
    for (size_t i = 0; i < stack.m_index; i++)
        out << stack.m_container[i] << " ";
    out << std::endl;
    return out;
}
template < typename T >
size_t Stack < T > ::getCurrentSize() {
    return m_index;
}
template < typename T >
Stack < T > ::~Stack() {
    std::cout << "stack destroctor" << std::endl;
    delete[] m_container;


}