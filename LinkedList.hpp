#pragma once

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class LinkedList {
    protected:
        struct Node {
            T data;
            Node* next;

            Node(T val = T(), Node* ptr = nullptr)
             : data(val), next(ptr) { }
        };
        
        Node* head;
        Node* getNode(int);

        int length;

        void copy(const LinkedList<T>&);

    public:
        LinkedList();
        LinkedList(LinkedList<T>&);
        LinkedList(const LinkedList<T>&);
        LinkedList(const LinkedList<T>*);
        virtual ~LinkedList();
        
        LinkedList<T>& operator=(const LinkedList<T>&);

        T getElement(int);
        T getElement(int) const;
        int getLength();
        bool isEmpty();

        void append(T&);
        void insert(T&, int);
        void replace(T&, int);
        void remove(int);
        void clear();

        shared_ptr<LinkedList<T>> getCopy() const;

        template <typename U>
        friend ostream& operator<<(ostream&, const LinkedList<U>&);
};


#include "LinkedList.tpp"