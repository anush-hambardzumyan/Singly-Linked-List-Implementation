#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

#include <iostream>

template <typename T>
class LinkedList
{
    public:
    class Node
    {
        public:
        T val;
        Node* next;

        public:
        Node(T element);
    };

    private:
    Node* head;
    size_t l_size;

    public:

    LinkedList();                                   //done
    ~LinkedList();                                  //done
    //METHODS
    void push_back(const T& element);               //done
    void push_front(const T& element);              //done
    void pop_back();                                //done ??
    void pop_front();                               //done
    void print();                                   //done
    void assign(size_t quantity, const T& value);   //done 
    T& front();                                     //done
    T& back();                                      //done
    bool empty() const;                             //done  
    size_t size() const;                            //done    
    size_t max_size() const;                        //done
    void clear();                                   // ????
    void insert(size_t pos, const T& value);        //done
    void erase(size_t pos);                         //done
    void resize(size_t new_size);                   // ??some cases are not handled
    void swap(LinkedList<T>& another);              //done
    void reverse();                                 //done ??
    void sort();                                    //done
    Node* getHead() const 
    {
        return head;
    }
};

template<typename T>    //done
bool operator ==(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template<typename T>    //done
bool operator !=(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template<typename T>    //done  
bool operator <(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template<typename T>    //done
bool operator >=(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template<typename T>
bool operator >(const LinkedList<T>& list1 , const LinkedList<T>& list2);

template<typename T>
bool operator <=(const LinkedList<T>& list1 , const LinkedList<T>& list2);



#include "implementations.hpp"

#endif