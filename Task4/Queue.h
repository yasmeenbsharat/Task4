#include <iostream>

#include "Stack.h"

template < typename T > class Queue;
template < typename T > std::ostream& operator << (std::ostream& out,
    Queue < T >& queue);
template < class T >

class Queue {

public:
    Queue();
    T pop();
    void push(const T& value);
    friend std::ostream& operator << < > (std::ostream& out,
        Queue& queue);

private:
    Stack < T > m_stack1;
    Stack < T > m_stack2;

};

template < class T >
Queue < T > ::Queue() {
    std::cout << "Queue constructor\n";
}

template < class T >
T Queue < T > ::pop() {

    std::cout << "Queue pop \n";

    if (m_stack2.isEmpty() && m_stack1.isEmpty())
        exit(0);

    while (!m_stack1.isEmpty())
        m_stack2.push(m_stack1.pop());

    return m_stack2.pop();

}

template < class T >
void Queue < T > ::push(const T& value) {
    std::cout << "Queue push\n";
    m_stack1.push(value);
}

template < class T >
std::ostream& operator << (std::ostream& out,
    Queue < T >& queue) {

    if (!(queue.m_stack2.isEmpty()))
        for (size_t i = queue.m_stack2.getVector().size(); i > 0; i--)
            out << queue.m_stack2.getVector()[i - 1] << ", ";

    if (!(queue.m_stack1.isEmpty()))
        out << queue.m_stack1;

    out << std::endl;

    return out;
}