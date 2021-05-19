#ifndef LIST_H
#define LIST_H
//#include "linked_list_functions.h"
#include <iostream>

#include <string>

template <typename ITEM>
struct node{
    ITEM _data;
    node<ITEM>* _next;
    node(){};
    node(ITEM i): _data(i), _next(nullptr){};
};

template <class T>
class List
{
public:
    List();

    ~List();

    List(const List<T> &copyThis); //IN - list to copy

    List& operator =(const List& RHS);  //IN - list to copy

    bool operator ==(const List& rhs){  //IN - list to compare
        node<T>* w = this->head;        // CALC - to traverse
        node<T>* w2 = rhs.head;         // CALC - to traverse rhs

        while(w || w2){
            if (!(w->_item == w2->_item)){
                return false;
            }
            w = w->_next;
            w2 = w2->_next;
        }
        return true;
    }


    bool isEmpty() const;

    node<T>* append(T i);

    T Delete(const T& iMarker);         // IN - delete node pointed by iMarker

    void clear();

    void Print() const;

    node<T>* Search(const T &key);      //IN - search for this value

    int find(const T &key);      //IN - search for this value

    T& operator[](int index);           //IN - index to access

    node<T>* Begin() const; // return head

    node<T>* End() const; // return tail

    int size() const { return _size; };

private:
    node<T>* head = nullptr;      //ATT - front of list
    node<T>* tail = nullptr;
    int _size = 0;
};

template<class T>
bool List<T>::isEmpty() const{
    return (this->head == nullptr);
}

template <class T>
List<T>::List(){
    head = nullptr;
    tail = nullptr;
}

template <class T>
List<T>::List(const List<T> &copyThis){
    for(node<T>* curr = copyThis.head; curr != nullptr; curr = curr->_next){
        append(curr->_data);
    }
}

template<class T>
List<T>::~List(){
    clear();
}

template <class T>
List<T>& List<T>::operator=(const List& RHS){
    this->clear();
    for(node<T>* curr = RHS.head; curr != nullptr; curr = curr->_next){
        append(curr->_data);
    }

    return *this;
}

template<class T>
T List<T>::Delete(const T& iMarker){        //IN - delete this
    if(head->_data == iMarker){
        node<T>* temp = head;
        head = head->_next;
        delete temp;
        _size--;
        if(isEmpty()){
            head = tail = nullptr;
        } else if(_size == 1){ // delete head, update to point to tail
            head = tail;
        }
        return iMarker;
    }

    for(node<T>* current = head; current->_next != nullptr; current = current->_next){
        if(current->_next->_data == iMarker){
            node<T>* temp = current->_next;
            current->_next = temp->_next;
            delete temp;
            if(--_size == 1){ // delete tail update to point to head
                tail = head;
            }

            return iMarker;
        }
    }

    throw "Does not exist";
}

template <class T>
void List<T>::clear(){
    for(node<T>* curr = head; curr != nullptr;){
        node<T>* temp = curr;
        curr = curr->_next;
        delete temp;
    }
    _size = 0;
}

template<class T>
node<T>* List<T>::Search(const T &key){     //IN - search for this
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next){
        if(curr->_data == key){
            return curr;
        }
    }

    throw "Does not exist";
}

template<class T>
int List<T>::find(const T &key){     //IN - search for this
    int index = 0;
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next, index++){
        if(curr->_data == key){
            return index;
        }
    }
    return -1;
}

template<class T>
T& List<T>::operator[](int index){  //IN - position of element
    int pos = 0;
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next, pos++){
        if(pos == index){
            return curr->_data;
        }
    }
    std::cout << index << "out of bounds";
    throw std::to_string(index) + "Out of bounds";
}

template<class T>
node<T>* List<T>::Begin() const{
    return head;
}

template<class T>
node<T>* List<T>::End() const{
    return tail;
}

template <class T>
node<T>* List<T>::append(T i){
    _size++;
    if(isEmpty()){
        tail = head = new node<T>(i);
        return head;
    }

    tail->_next = new node<T>(i);
    tail = tail->_next;
    return tail;
}


#endif // LIST_H
