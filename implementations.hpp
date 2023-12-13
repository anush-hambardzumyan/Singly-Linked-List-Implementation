#include "prototypes.hpp"

//DEFAULT CONSTRUCTOR
template<typename T>
LinkedList<T>::LinkedList() :l_size(0) , head(nullptr)
{}

//DESTRUCTOR
template<typename T>
LinkedList<T>::~LinkedList()
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
void LinkedList<T>::insert(size_t pos, const T& value)
{
    if((!head && pos == 0) || pos == 0)
    {
        push_front(value);
        return;
    }

    if(pos == l_size)
    {
        push_back(value);
        return;
    }

    if(pos > l_size)
    {
        std::cout << "Invalid operation. Out of range: " << std::endl;
        return;
    }

    Node* tmp = head;
    size_t pos_counter = 0;
    while(pos_counter < pos - 1)
    {
        tmp = tmp -> next;
        ++pos_counter;
    }

    Node* new_node = new Node(value);

    new_node->next = tmp->next;
    tmp->next = new_node;

    l_size++;
}

//ERASE
template<typename T>
void LinkedList<T>::erase(size_t pos)
{
    if (!head)
    {
        std::cout << "Invalid operation. List is empty." << std::endl;
        return;
    }

    if (pos >= l_size)
    {
        std::cout << "Invalid operation. Out of range." << std::endl;
        return;
    }

    if (pos == 0)
    {
        pop_front(); 
        return;
    }

    Node* tmp = head;
    size_t pos_counter = 0;

    while (pos_counter < pos - 1)
    {
        tmp = tmp->next;
        ++pos_counter;
    }

    Node* to_delete = tmp->next;
    tmp->next = to_delete->next;

    delete to_delete;
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

//SORT
template<typename T>
void LinkedList<T>::sort()
{
    Node* current = head;
    Node* minimum = head;
    Node* tmp = head;
    Node* n_node;
    Node* curr_next_node;

    tmp = current->next;
    while (tmp)
    {
        if (minimum->val > tmp->val)
        {
            minimum = tmp;
        }
        tmp = tmp->next;
    }
    n_node = minimum->next;
    current->next = n_node;
    minimum->next = head;
    head = minimum;

    current = head;
    minimum = head;
    tmp = head;
    Node* tmp_min_back = nullptr;
    Node* min_back = nullptr;

    while (current->next)
    {
        minimum = current;
        tmp = current->next;
        tmp_min_back = current;
        while (tmp)
        {
            if (minimum->val > tmp->val)
            {
                minimum = tmp;
                min_back = tmp_min_back;
            }
            tmp = tmp->next;
            tmp_min_back = tmp_min_back->next;
        }
        n_node = minimum->next;
        curr_next_node = current->next;
        current->next = minimum;
        minimum->next = curr_next_node;
        min_back->next = n_node;
    }
}

//MERGE
template <typename T>
void LinkedList<T>::merge(LinkedList<T>& another)
{
    if(another -> head -> val > this -> head -> val)
    {
        std::swap(another,this);
    }

    Node* tmp_head1 = this -> head;
    Node* tmp_head2 = another -> head;

    while(tmp_head2 != nullptr)
    {
        if(tmp_head1 -> val < tmp_head2 -> val)
        {
            if(tmp_head1 -> next -> val < tmp_head2 -> val)
            {
                tmp_head1 = tmp_head1 -> next;             
                continue;
            }    
        }

        if(tmp_head1 -> val == tmp_head2 -> val)
        {
            Node* tmp_next1 = tmp_head1 -> next;
            Node* tmp_next2 = tmp_head2 -> next;
            tmp_head1 -> next = tmp_head2;
            tmp_head2 -> next = tmp_next1;
            tmp_head2 = tmp_next2;
            tmp_head1 = tmp_head1 -> next;
        }
    }
}

//UNIQUE
template <typename T>
void LinkedList<T>::unique()
{
    if (!head)
    {
        return;
    }

    Node *tmp_head = head;
    Node *tmp_next = tmp_head->next;

    while (tmp_next)
    {
        if (tmp_head->val == tmp_next->val)
        {
            Node *temp = tmp_next;
            tmp_next = tmp_next->next;
            delete temp;
        }
        else
        {
            tmp_head->next = tmp_next;
            tmp_head = tmp_head->next;
            tmp_next = tmp_next->next;
        }
    }
    tmp_head->next = nullptr;
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

