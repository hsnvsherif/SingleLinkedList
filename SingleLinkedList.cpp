{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww30040\viewh18900\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <stdexcept>\
\
template <typename T>\
class Node \{\
public:\
    T data;\
    Node* next;\
\
    Node(T value, Node* nextPtr = nullptr) \{\
        data = value;\
        next = nextPtr;\
    \}\
\};\
\
template <typename T>\
class SinglyLinkedList \{\
private:\
    Node<T>* head;\
\
public:\
    SinglyLinkedList() : head(nullptr) \{\}\
\
    void addAtFront(T value) \{\
        head = new Node<T>(value, head);\
    \}\
\
    void addAtEnd(T value) \{\
        if (!head) \{\
            head = new Node<T>(value);\
            return;\
        \}\
        Node<T>* temp = head;\
        while (temp->next) \{\
            temp = temp->next;\
        \}\
        temp->next = new Node<T>(value);\
    \}\
\
    T removeFirst() \{\
        if (!head) \{\
            throw std::underflow_error("List is empty");\
        \}\
        Node<T>* oldHead = head;\
        T value = head->data;\
        head = head->next;\
        delete oldHead;\
        return value;\
    \}\
\
    int size() \{\
        int count = 0;\
        for (Node<T>* temp = head; temp; temp = temp->next) \{\
            count++;\
        \}\
        return count;\
    \}\
\
    Node<T>* find(T value) \{\
        for (Node<T>* temp = head; temp; temp = temp->next) \{\
            if (temp->data == value) \{\
                return temp;\
            \}\
        \}\
        return nullptr;\
    \}\
\
    void displayList() \{\
        for (Node<T>* temp = head; temp; temp = temp->next) \{\
            std::cout << temp->data << "->";\
        \}\
        std::cout << "NULL" << std::endl;\
    \}\
\};\
\
int main() \{\
    SinglyLinkedList<int> list;\
\
    list.addAtFront(5);\
    list.addAtFront(10);\
    list.addAtEnd(20);\
\
    list.displayList(); \
\
    std::cout << "Size of the list: " << list.size() << std::endl;\
\
    std::cout << "Enter the number to find: ";\
    int val;\
    std::cin >> val;\
\
    if (list.find(val)) \{\
        std::cout << "Entered value is on the list." << std::endl;\
    \} else \{\
        std::cout << "Entered value is not on the list." << std::endl;\
    \}\
\
    return 0;\
\}\
}