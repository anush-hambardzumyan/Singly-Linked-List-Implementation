#include "prototypes.hpp"

//DEFAULT CONSTRUCTOR
template<typename T>
LinkedList<T>::LinkedList() :l_size(0) , head(nullptr)
{}

//DESTRUCTOR
template<typename T>
LinkedList<T>::~LinkedList()     //?????
{
    // if(head)
    // {
    //     clear();
    // }
}

//NODE PARAMETRIZED CONSTRUCTOR
template<typename T>
LinkedList<T>::Node::Node(T value) : val(value) , next(nullptr)
{}

//PRINT
template<typename T>
void LinkedList<T>::print()
{
    Node* tmp = head;
    while(tmp)
    {
        std::cout << tmp -> val << " " ;
        tmp = tmp -> next;
    }
}

//PUSH_BACK
template<typename T>
void LinkedList<T>::push_back(const T& element)
{
    if(!head)
    {
        head = new Node(element);
    }

    else
    {
        Node* tmp = head;
        while(tmp -> next)
        {
            tmp = tmp -> next;
        }
        tmp -> next = new Node(element);
    }
    ++l_size;
}

//PUSH_FRONT
template<typename T>
void LinkedList<T>::push_front(const T& element)
{
    if(!head)
    {
        head = new Node(element);
    }

    else
    {
        Node* tmp = new Node(element);
        tmp -> next = head;
        head = tmp;
    }
    ++l_size;
}

//POP_BACK
template<typename T>
void LinkedList<T>::pop_back()
{
    if (!head)
    {
        return;
    }

    if (head->next == nullptr) 
    {
        delete head;
        head = nullptr;
        --l_size;
        return;
    }

    Node* tmp = head;
    while(tmp -> next != nullptr && tmp -> next -> next != nullptr)
    {
        tmp = tmp -> next;
    }
    delete tmp -> next;
    tmp -> next = nullptr;
    --l_size;
}

//POP_FRONT
template<typename T>
void LinkedList<T>::pop_front()
{
    if(!head)
    {
        std::cout << "unvalid operation: " << std::endl;
        return;
    }

    if(head -> next == nullptr)
    {
        delete head;
        head = nullptr;
        --l_size;
        return;
    }

    Node* tmp = head -> next;
    delete head;
    head = tmp;
    --l_size;
}

//FRONT
template<typename T>
T& LinkedList<T>::front()
{
    if(!head)
    {
        std::cout << "no elements in list: " << std::endl;
        exit(0);
    }
    return head -> val;
}

//BACK
template<typename T>
T& LinkedList<T>::back()
{
    if(!head)
    {
        std::cout << "no elements in list: " << std::endl;
        exit(0);
    }

    Node* tmp = head;
    while(tmp -> next)
    {
        tmp = tmp -> next;
    }

    return tmp -> val;
}

//ASSIGN
template<typename T>
void LinkedList<T>::assign(size_t quantity, const T& value)
{
    if(head)
    {
        clear();
    }    

    l_size = quantity;
    Node* new_head = nullptr;
    Node* current = nullptr;

    for (size_t i = 0; i < l_size; ++i)
    {
        Node* new_node = new Node(value);
        
        if (!new_head) 
        {
            new_head = new_node;
            current = new_head;
        } 

        else 
        {
            current -> next = new_node;
            current = new_node;
        }
    }

    head = new_head;

}

//EMPTY
template<typename T>
bool LinkedList<T>::empty() const
{
    return head == nullptr;
}

//SIZE
template<typename T>
size_t LinkedList<T>::size() const
{
    return l_size;
}

//MAX_SIZE
template<typename T>
size_t LinkedList<T>::max_size() const
{
    return 768614336404564650;
}

//CLEAR          
template<typename T>
void LinkedList<T>::clear()
{
    while (head)
    {
        Node* p = head;
        head = head -> next;
        delete p;
    }

    head = nullptr;
    l_size = 0;
}

//INSERT
template<typename T>
void LinkedList<T>::insert(iterator pos, const T& value)
{
    if((!head && pos == begin()) || pos == begin())
    {
        push_front(value);
        return;
    }

    iterator it = begin();
    Node* curr = head;
    Node* prev = nullptr;
    while(it != pos)
    {
        prev = curr;
        curr = curr -> next;
        ++it;
    }

    prev->next = new Node(value);
    prev->next->next = curr;

    l_size++;
}

//ERASE
template<typename T>
void LinkedList<T>::erase(iterator& pos)
{
    
    if (!head)
    {
        std::cout << "Invalid operation. List is empty." << std::endl;
        return;
    }
    // iterator i = begin();

    if (pos == begin())
    {
        pop_front(); 
        // std::cout << 10;
        return;
    }
   

    Node* curr = head;
    Node* prev = nullptr;
    iterator pos_counter = begin();
    iterator current = pos_counter;
    
    while (pos_counter != pos)
    {
        current = pos_counter;
        prev = curr;
        curr = curr -> next;
        ++pos_counter;
    }

    pos = current;
    prev->next = curr->next;
    delete curr;
    curr = nullptr;
    --l_size;
}


//RESIZE  
template<typename T>
void LinkedList<T>::resize(size_t new_size)
{
    if(new_size > max_size())
    {
        std::cout << "Invalid operation. Out of range: " <<std::endl;
        return;
    }

    if(new_size == 0)
    {
        clear();
        return;
    }

    if(new_size == l_size - 1)
    {
        return;
    }

    if(new_size < l_size - 1)
    {
        Node* tmp = head;
        size_t counter = 0;

        while (counter < new_size - 1)
        {
            tmp = tmp->next;
            ++counter;
        }

        Node* del = tmp->next;
        while (del)
        {
            tmp->next = del->next;
            delete del;
            del = tmp->next;
        }

        l_size = new_size;
        return;
    }

    else
    {
        size_t counter = 0;
        Node* tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp -> next;
        }

        while(counter <= new_size - l_size - 1)
        {
            Node* new_node = new Node(0);
            tmp -> next = new_node;
            tmp = tmp -> next;
            ++counter;
        }
    }
}

//SWAP
template<typename T>
void LinkedList<T>::swap(LinkedList<T>& another)
{
    std::swap(head , another.head);
    std::swap(l_size , another.l_size);
}

//REVERSE
template<typename T>
void LinkedList<T>::reverse()
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr != nullptr)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

///// ITERATORS
//BEGIN
template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
    return iterator(head);
} 

//END
template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    return iterator(nullptr);
}


//OPERATORS
template<typename T>
bool operator==(const LinkedList<T>& list1 , const LinkedList<T>& list2)
{
    if(list1.size() != list2.size())
    {
        return false;
    }

    std::vector<T> vec1;
    typename LinkedList<T>::Node* tmp1 = list1.getHead();
    while(tmp1)
    {
        vec1.push_back(tmp1 -> val);
        tmp1 = tmp1 -> next;
    }

    std::vector<T> vec2;
    typename LinkedList<T>::Node* tmp2 = list2.getHead();
    while(tmp2)
    {
        vec2.push_back(tmp2 -> val);
        tmp2 = tmp2 -> next;
    }

    for(size_t i = 0; i < vec1.size(); ++i)
    {
        if(vec1[i] != vec2[i])
        {
            return false;
        }
    }

    return true;
}

template<typename T>
bool operator !=(const LinkedList<T>& list1 , const LinkedList<T>& list2)
{
    if(list1 == list2)
    {
        return false;
    }

    return true;
}

template<typename T>
bool operator<(const LinkedList<T>& list1, const LinkedList<T>& list2)
{
    if (list1.size() < list2.size())
    {
        return true;
    }

    else if (list1.size() > list2.size())
    {
        return false;
    }

    typename LinkedList<T>::Node* tmp1 = list1.getHead();
    typename LinkedList<T>::Node* tmp2 = list2.getHead();

    std::vector<T> vec1;
    std::vector<T> vec2;
    
    while (tmp1)
    {
        vec1.push_back(tmp1->val);
        tmp1 = tmp1->next;
    }

    while (tmp2)
    {
        vec2.push_back(tmp2->val);
        tmp2 = tmp2->next;
    }

    for (size_t i = 0; i < vec1.size(); ++i)
    {
        if (vec1[i] < vec2[i])
        {
            return true;
        }

        else if (vec1[i] > vec2[i])
        {
            return false;
        }
    }

    return false;
}

template<typename T>
bool operator >=(const LinkedList<T>& list1 , const LinkedList<T>& list2)
{
    if(list1 < list2)
    {
        return false;
    }

    return true;
}

