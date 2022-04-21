#include <iostream>

#include <vector>

template < typename T >

class Stack {

public:
    Stack();
    void pop();
    void push(const T& value);
    std::vector < T >& getVector();
    bool empty();
    void printStack();
    friend std::ostream& operator << (std::ostream& out,
        const Stack < T >& stack);

private:
    std::vector < T > m_v;

};

template < class T >
Stack < T > ::Stack() {
    std::cout << "Stack constructor\n";
}
template < typename T >
void Stack < T > ::pop() {
    std::cout << "Stack pop \n";
    if (!m_v.empty())
        m_v.pop_back();

}

template < typename T >
void Stack < T > ::push(const T& value) {
    std::cout << "Stack push\n";
    m_v.push_back(value);

}
template < typename T >
std::vector < T >& Stack < T > ::getVector() {
    return m_v;
}

template < typename T >
bool Stack < T > ::empty() {
    return m_v.empty();
}

template < typename T >
std::ostream& operator << (std::ostream& out,
    const Stack < T >& stack) {
    for (size_t i = 0; i < stack.m_v.size(); i++)
        out << stack.m_v[i] << " ";
    return out;
}

template < class T >
void Stack < T > ::printStack() {
   
    for (size_t i = 0; i < m_v.size(); i++)
        std::cout << m_v[i] << ", ";
    std::cout << std::endl;

}