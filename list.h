#ifndef LIST_H
#define LIST_H
//#include "linked_list_functions.h"
#include <iostream>

#include <string>
/****************************************************************
 * node struct
 *   This struct represents a node in a doubly-linked list.
 ***************************************************************/
template <typename ITEM>
struct node{
    ITEM _data;            // IN - data value to hold
    node<ITEM>* _next;     // IN - pointer to next item
    node<ITEM>* _previous; // IN - pointer to previous item
    node(){};
    node(ITEM i): _data(i), _next(nullptr), _previous(nullptr){};
};

template <class T>
class List
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    List();

    ~List();

    List(const List<T> &copyThis); //IN - list to copy

    /**************
     ** MUTATORS **
     **************/
    List& operator =(const List& RHS);  //IN - list to copy

    node<T>* append(T i);

    T Delete(const T& iMarker);         // IN - delete node pointed by iMarker

    bool Delete(int i);

    void clear();

    void sort(bool (*compare)(node<T>&, node<T>&));

    /***************
     ** ACCESSORS **
     ***************/

    node<T>* Search(const T &key) const;      //IN - search for this value

    int find(const T &key) const;      //IN - search for this value

    T& operator[](int index);           //IN - index to access

    bool isEmpty() const {return _size == 0;};

    node<T>* Begin() const; // return head

    node<T>* End() const; // return tail

    int size() const { return _size; };

private:
    node<T>* head = nullptr; // ATT - front of list
    node<T>* tail = nullptr; // ATT - end of list
    int _size = 0;           // IN  - size of list
};
/****************************************************************
 * list Class
 *   This class represents a linked list. It keeps track of a
 *   node with a head and a tail.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * list();
 *   Constructor; Initialize class attributes to nullptr
 *   Parameters: none
 *   Return: none
 ***************************************************************/
template <class T>
List<T>::List(){
    head = nullptr;
    tail = nullptr;
}

/****************************************************************
 * list(const List<T> &copyThis);
 *   copy constructor; creates a new list that is identical to
 *                     the parameter
 *   Parameters: none
 *   Return: none
 ***************************************************************/
template <class T>
List<T>::List(const List<T> &copyThis){
    for(node<T>* curr = copyThis.head; curr != nullptr; curr = curr->_next){
        append(curr->_data);
    }
}

/****************************************************************
 * ~list();
 *   Destructor; calls helper function clear to delete all
 *               elements in the list
 *   Parameters: none
 *   Return: none
 ***************************************************************/
template<class T>
List<T>::~List(){
    clear();
}

/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * List<T>& List<T>::operator=(const List& RHS);
 *
 *   Mutator; This method will clear the list and make it identical
 *            to the parameter
 *------------------------------------------------------------------
 *   Parameter: RHS (List&) // IN – list to copy
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
template <class T>
List<T>& List<T>::operator=(const List& RHS){
    this->clear();
    for(node<T>* curr = RHS.head; curr != nullptr; curr = curr->_next){
        append(curr->_data);
    }

    return *this;
}

/*******************************************************************
 * T List<T>::Delete(const T& iMarker);
 *
 *   Mutator; This method will delete the given parameter if found
 *            in the list.
 *------------------------------------------------------------------
 *   Parameter: iMarker (T&) // IN – item to delete
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
template<class T>
T List<T>::Delete(const T& iMarker){        //IN - delete this
    std::cout << "Deleting" << std::endl;
    if(isEmpty()){
        throw "Trying to delete on an empty list";
    }
    // if the target is the first value
    if(head->_data == iMarker){
        node<T>* temp = head;
        head = head->_next;
        delete temp;
        _size--;
        if(isEmpty()){
            tail = nullptr;
        } else if(head == tail){
            tail->_previous = nullptr;
        }
        return iMarker;
    }
    // if target is the last value
    if(tail->_data == iMarker){
        _size--;
        node<T>* temp = tail;
        tail = tail->_previous;
        tail->_next = nullptr;
        delete temp;

        return iMarker;
    }
    // target is found in the middle
    for(node<T>* current = head; current != tail;){
        if(current->_data == iMarker){
            std::cout << "Found" << std::endl;
            current->_previous->_next = current->_next;
            current->_next->_previous = current->_previous;
            delete current;
            _size--;

            return iMarker;
        }
        current = current->_next;
    }


    throw "Does not exist";
}

/*******************************************************************
 * bool List<T>::Delete(int i);
 *
 *   Mutator; This method will delete the node at the given index
 *            if found in the list.
 *------------------------------------------------------------------
 *   Parameter: i (int) // IN – index to delete
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
template <class T>
bool List<T>::Delete(int i) // IN - index of node to delete
{
    std::cout << "Deleting" << std::endl;
    if(isEmpty()){
        throw "Trying to delete on an empty list";
    }

    if(i == 0){
        node<T>* temp = head;
        head = head->_next;
        delete temp;
        _size--;
        if(isEmpty()){
            tail = nullptr;
        } else if(head == tail){
            tail->_previous = nullptr;
        }
        return true;
    }

    if(i == _size-1){
        _size--;
        node<T>* temp = tail;
        tail = tail->_previous;
        tail->_next = nullptr;
        delete temp;

        return true;
    }

    int pos = 0;
    for(node<T>* current = head; current != tail;pos++){
        if(pos == i){
            std::cout << "Found" << std::endl;
            current->_previous->_next = current->_next;
            current->_next->_previous = current->_previous;
            delete current;
            _size--;

            return true;
        }
        current = current->_next;
    }

    throw "Does not exist";
    return false;
}

/*******************************************************************
 * void List<T>::clear();
 *
 *   Mutator; This method will delete all items in the list
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
template <class T>
void List<T>::clear(){
    for(node<T>* curr = head; curr != nullptr;){
        node<T>* temp = curr;
        curr = curr->_next;
        delete temp;
    }
    this->head = this->tail = nullptr;
    _size = 0;
}

/*******************************************************************
 * node<T>* List<T>::append(T i);
 *
 *   Mutator; This method will add the given item at the end of the
 *            list
 *------------------------------------------------------------------
 *   Parameter: i (T) // IN - item to insert
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
template <class T>
node<T>* List<T>::append(T i){
    if(_size == 0){
        _size++;
        tail = head = new node<T>(i);
        return head;
    }

    _size++;
    tail->_next = new node<T>(i);
    tail->_next->_previous = tail;
    tail = tail->_next;

    return tail;
}

/*******************************************************************
 * void List<T>::sort(bool (*compare)(node<T>&, node<T>&));
 *
 *   Mutator; This method will sort the list using the given
 *            comparator
 *------------------------------------------------------------------
 *   Parameter: compare (bool*) // IN - comparator function
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
template <class T>
void List<T>::sort(bool (*compare)(node<T>&, node<T>&)){
    if(isEmpty()){
        return;
    }

    for(node<T>* curr = head->_next; curr != nullptr; curr = curr->_next){
        node<T>* temp = curr;
        while(temp != head && compare(*temp, *temp->_previous)){
            T t = temp->_data;
            temp->_data = temp->_previous->_data;
            temp->_previous->_data = t;
            temp = temp->_previous;
        }
    }
}

 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * node<T>* Search(const T &key) const;
 *
 *   Accessor; This method will return the node that contains
 *             the given key
 * --------------------------------------------------------------
 *   Parameters: key (const T&) // IN - data to search for
 * --------------------------------------------------------------
 *   Return: node<T>*  // pointer to node that contains key
 ***************************************************************/
template<class T>
node<T>* List<T>::Search(const T &key) const //IN - search for this
{
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next){
        if(curr->_data == key){
            return curr;
        }
    }

    throw "Does not exist";
}

/****************************************************************
 * int find(const T &key) const;
 *
 *   Accessor; This method will return the index of the node that
 *             contains the given key
 * --------------------------------------------------------------
 *   Parameters: key (const T&) // IN - data to search for
 * --------------------------------------------------------------
 *   Return: int  // index of node that contains key
 ***************************************************************/
template<class T>
int List<T>::find(const T &key) const {     //IN - search for this
    int index = 0;
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next, index++){
        if(curr->_data == key){
            return index;
        }
    }
    return -1;
}

/****************************************************************
 * T& operator[](int index) const;
 *
 *   Accessor; This method will return the data value at the given
 *             index
 * --------------------------------------------------------------
 *   Parameters: index (int) // IN - index to search for
 * --------------------------------------------------------------
 *   Return: T&  // data value at index
 ***************************************************************/
template<class T>
T& List<T>::operator[](int index){  //IN - position of element
    int pos = 0;
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next, pos++){
        if(pos == index){
            return curr->_data;
        }
    }
    std::cout << index << " out of bounds";
    throw std::to_string(index) + " Out of bounds";
}

/****************************************************************
 * node<T>* Begin() const;
 *
 *   Accessor; This method will return the head node
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: node<T>*  // pointer to head node or nullptr
 ***************************************************************/
template<class T>
node<T>* List<T>::Begin() const {
    return head;
}

/****************************************************************
 * node<T>* End() const;
 *
 *   Accessor; This method will return the tail node
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: node<T>*  // pointer to tail node or nullptr
 ***************************************************************/
template<class T>
node<T>* List<T>::End() const {
    if(isEmpty()){
        return head;
    }

    return tail->_next; // nullptr
}


#endif // LIST_H
