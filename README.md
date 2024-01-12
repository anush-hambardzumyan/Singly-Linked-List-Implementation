# Singly-Linked-List-Implementation

A **singly linked list** is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer.
Linked List can be defined as collection of objects called nodes that are randomly stored in the memory. 
Till now, we were using array data structure to organize the group of elements that are to be stored individually in the memory. However, Array has several advantages and disadvantages which must be known in order to decide the data structure which will be used throughout the program.
![Linked-List-Data-Structure](https://github.com/anush-hambardzumyan/Singly-Linked-List-Implementation/assets/66312436/8088bbb4-6ad2-4c40-aca7-938886ee8b48)

______
**Properties of Linked List**
* A node contains two fields i.e. data stored at that particular address and the pointer which contains the address of the next node in the memory.
* The last node of the list contains pointer to the null.
* The list is not required to be contiguously present in the memory. The node can reside any where in the memory and linked together to make a list. This achieves optimized utilization of space.
* List size is limited to the memory size and doesn't need to be declared in advance.
* Empty node can not be present in the linked list.
* We can store values of primitive types or objects in the singly linked list.

____
### Complexity
Linked lists have most of their benefit when it comes to the insertion and deletion of nodes in the list. Unlike the dynamic array, insertion and deletion at any part of the list takes constant time.

However, unlike dynamic arrays, accessing the data in these nodes takes linear time because of the need to search through the entire list via pointers. It's also important to note that there is no way of optimizing search in linked lists. In the array, we could at least keep the array sorted. However, since we don't know how long the linked list is, there is no way of performing a binary search:


| Operation | Average | Worst Case |
| :----: | :----: | :----: |
| Access | O(n) | O(n) |
| Search | O(n) | O(n) |
| Insertion | O(1) |  O(1) |
| Deletion | O(1) |  O(1) |

![insertion-operation-of-linked-list](https://github.com/anush-hambardzumyan/Singly-Linked-List-Implementation/assets/66312436/e7fa48b2-ae7e-43f3-ae64-2d5cb93fc81f)



_________
This implementation also includes nested iterator class, and in some methods , like std::list , self-made iterators are used. <br>
**This implementation includes following methods**
- [x] Constructor
- [x] Destructor
- [x] push_back
- [x] push_front
- [x] print
- [x] assign
- [x] front
- [x] back
- [x] empty
- [x] size
- [x] max_size
- [x] clear
- [x] insert
- [x] erase
- [x] resize
- [x] swap
- [x] reverse

