#include <iostream>

#include <vector>

template < typename T > class Stack;
template < typename T > std::ostream& operator << (std::ostream& out,
    const Stack < T >& stack);

template < typename T >
class Stack {

public:
    Stack();
    T pop();
    void push(const T& value);
    std::vector < T >& getVector();
    bool isEmpty();
    friend std::ostream& operator << < > (std::ostream& out,
        const Stack& stack);

private:
    std::vector < T > m_vector;

};

template < class T >
Stack < T > ::Stack() {
    std::cout << "Stack constructor\n";
}
template < typename T >
T Stack < T > ::pop() {
    std::cout << "Stack pop \n";
    if (m_vector.empty())
        exit(0);
    T t = m_vector.back();
    m_vector.pop_back();
    return t;

}

template < typename T >
void Stack < T > ::push(const T& value) {
    std::cout << "Stack push\n";
    m_vector.push_back(value);

}
template < typename T >
std::vector < T >& Stack < T > ::getVector() {
    return m_vector;
}

template < typename T >
bool Stack < T > ::isEmpty() {
    return m_vector.empty();
}

template < typename T >
std::ostream& operator << (std::ostream& out,
    const Stack < T >& stack) {
    for (size_t i = 0; i < stack.m_vector.size(); i++)
        out << stack.m_vector[i] << " ";
    out << std::endl;
    return out;
}