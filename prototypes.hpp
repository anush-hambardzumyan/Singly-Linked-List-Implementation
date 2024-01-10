#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

#include <iostream>

template <typename T>
class LinkedList
{
    public:
    struct Node
    {
        public:
        T val;
        Node* next;
        Node(T element);
    };

    private:
    Node* head;
    size_t l_size;

    public:
    LinkedList();                                   //done
    ~LinkedList();                                  //done


    //NESTED ITERATORS CLASS
    class iterator
    {
        private:
            Node* it_ptr;

        public:
            iterator() : it_ptr(nullptr) {}
            iterator(Node* ptr) : it_ptr(ptr) {}
            ~iterator(){}
            T& operator*();
            iterator& operator=(const LinkedList<T>::iterator& it);
            bool operator==(const LinkedList<T>::iterator& it);
            bool operator!=(const LinkedList<T>::iterator& it);
            iterator& operator++();
            iterator operator++(int); 
    };

    //METHODS
    void push_back(const T& element);               //done
    void push_front(const T& element);              //done
    void pop_back();                                //done 
    void pop_front();                               //done
    void print();                                   //done
    void assign(size_t quantity, const T& value);   //done 
    T& front();                                     //done  
    T& back();                                      //done
    bool empty() const;                             //done  
    size_t size() const;                            //done    
    size_t max_size() const;                        //done
    void clear();                                   //done
    void insert(iterator pos, const T& value);      //done
    void erase(iterator& pos);                       //done
    void resize(size_t new_size);                   //done
    void swap(LinkedList<T>& another);              //done
    void reverse();                                 //done
    iterator begin();                               //done
    iterator end();                                 //done
    Node* getHead() const 
    {
        return head;
    }  
};

template <typename T>    //done
bool operator ==(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template <typename T>    //done
bool operator !=(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template <typename T>    //done  
bool operator <(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template <typename T>    //done
bool operator >=(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template <typename T>
bool operator >(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template <typename T>
bool operator <=(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template <typename T>
T& LinkedList<T>::iterator::operator*()
{
    return this -> it_ptr -> val;
}

template <typename T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator=(const LinkedList<T>::iterator& itr) 
{
    if (this != &itr) 
    {
        this -> it_ptr = itr.it_ptr;
    }
    return *this;
}

template <typename T>
bool LinkedList<T>::iterator::operator==(const LinkedList<T>::iterator& itr)
{
    return this -> it_ptr == itr.it_ptr;
}

template <typename T>
bool LinkedList<T>::iterator::operator != (const LinkedList<T>::iterator& itr)
{
    return (this -> it_ptr != itr.it_ptr);
}

template <typename T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++()
{
    this -> it_ptr = this -> it_ptr -> next;
    return *this;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++(int)
{
    iterator tmp = *this; // Create a copy of the current iterator
    it_ptr = it_ptr -> next;
    return tmp;
}

#include "implementations.hpp"

#endif