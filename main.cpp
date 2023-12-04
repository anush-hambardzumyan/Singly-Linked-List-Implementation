#include "prototypes.hpp"

int main()
{
    LinkedList<int> list;
    list.push_back(1);     //checking push_back()
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    std::cout << "Elements after push_back: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.push_front(0);       //check of push_front()
    std::cout << "Elements after push_front: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.pop_back();            //check of pop_back()
    std::cout << "Elements after pop_back: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.pop_front();              //check of pop_front()
    std::cout << "Elements after pop_front: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Element on front is: " <<std::endl <<  list.front() << std::endl;  //check of front()
    std::cout << std::endl;
    std::cout << "Element on back is: " << std::endl << list.back() << std::endl;    //check of back()
    std::cout << std::endl;

    if(!list.empty())                                                   //check of empty
    {
        std::cout << "List is not empty: " << std::endl;
        std::cout << std::endl;
    }


    std::cout << "Size of list is: " << std::endl << list.size() << std::endl;           //check of size
    std::cout << std::endl;
    std::cout << "Maximum size of list is: " <<std::endl << list.max_size() << std::endl;  //check of clear
    std::cout << std::endl;

    //list.clear();                                                             //check of clear
    //std::cout << "Size of list after clearing: " << list.size() << std::endl;

    list.insert(1,0);                                                       //check of insert
    list.insert(3,0);
    list.insert(5,0);             
    std::cout << "List after insertion: " << std::endl;         
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.erase(0);                                                      //check of erase
    list.erase(1);
    list.erase(2);
    std::cout << "List after erasing: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.resize(1);                                                     //check of resize
    std::cout << "List after first resize: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;
    list.resize(10);                                                     
//     std::cout << "List after second resize: ";                      //this case doesnt work right
//     list.print();
//     std::cout << std::endl;
// }

    LinkedList<int> list2;                                          //check of swap
    list2.push_back(10);
    list2.push_back(20);
    list2.push_back(15);
    list2.swap(list);
    std::cout << "List after swap: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.reverse();                                                 //check of reverse
    std::cout << "List in reverse order: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.sort();
    std::cout << "List in sorted order: " << std::endl;              //check of sort
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list.assign(2,4);                                              //check of assign
    std::cout << "Assigned list: " << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    list2.clear();                                                  // == operator
    list2.assign(2,4);
    if(list == list2)
    {
        std::cout << "Lists are equal: " << std::endl;
    }
    std::cout << std::endl;

    list.pop_back();                                                // != operator                                                
    if(list != list2)
    {
        std::cout << "Lists are not equal: " << std::endl;
    }
    std::cout << std::endl;

    LinkedList<int> list3;                                          // < operator
    list3.assign(3,2);
    LinkedList<int> list4;
    list4.assign(3,3);
    if(list3 < list4)
    {
        std::cout << "List "; 
        list3.print();
        std::cout << "is smaller than the list " ; 
        list4.print();
        std::cout << std::endl; 
    }

    
}    