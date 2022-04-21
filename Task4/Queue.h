#include <iostream>

#include "Stack.h"

template < class T >

class Queue {

public:
    Queue();
    void pop();
    void push(const T& value);
    void printQueue();
    friend std::ostream& operator << (std::ostream& out,
        const Queue < T >& queue);

private:
    Stack < T > m_s;
    Stack < T > m_s2;

};

template < class T >
Queue < T > ::Queue() {
    std::cout << "Queue constructor\n";
}

template < class T >
void Queue < T > ::pop() {

    std::cout << "Queue pop \n";

        if (!m_s2.empty())
            m_s2.pop();
        else {
            if(!m_s.empty()){
            while (!m_s.empty()) {
                m_s2.push(m_s.getVector().back());
                m_s.pop();
            }
            m_s2.pop();
            }
        }

    }



template < class T >
void Queue < T > ::push(const T& value) {
    std::cout << "Queue push\n";
    m_s.push(value);
}

template < class T >
std::ostream& operator << (std::ostream& out,
    const Queue < T >& queue) {
    out << queue.getStack();
    return out;
}

template < class T >
void Queue < T > ::printQueue() {

    if (!m_s2.empty())
        for (size_t i = m_s2.getVector().size(); i > 0; i--)
            std::cout << m_s2.getVector()[i - 1] << ", ";

    if (!m_s.empty())
        m_s.printStack();

    std::cout << std::endl;

}