#ifndef LIST_H
#define LIST_H
//#include "linked_list_functions.h"

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
    node<T>* InsertHead(T i);       //IN - value to insert

    node<T>* InsertAfter(T i,       //IN - value to insert
                 node<T>* iMarker); //IN - insert aftert this marker

    node<T>* append(T i);


    node<T>* InsertBefore(T i,          //IN - value to insert
                node<T>* iMarker);      //IN - insert before this marker


    node<T>* InsertSorted(T i);         // IN - insert i. Assume sorted list


    T Delete(const T& iMarker);         // IN - delete node pointed by iMarker


    void Print() const;


    node<T>* Search(const T &key);      //IN - search for this value
    node<T>* Search(const std::string &key);      //IN - search for this value
    int find(const T &key);      //IN - search for this value


    node<T>* Prev(node<T>* iMarker);    //IN - find node previous to this


    T& operator[](int index);           //IN - index to access

    node<T>* Begin() const;


    node<T>* End() const;

    int size() const { return _size; };



private:
    node<T>* head;      //ATT - front of list
    node<T>* tail;
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
    for(node<T>* curr = head; curr != nullptr;){
        node<T>* temp = curr;
        curr = curr->_next;
        delete temp;
    }
//    _ClearList(head);
}

template <class T>
List<T>& List<T>::operator=(const List& RHS){
    for(node<T>* curr = RHS.head; curr != nullptr; curr = curr->_next){
        append(curr->_data);
    }

    return *this;
}

template<class T>
T List<T>::Delete(const T& iMarker){        //IN - delete this
    _size--;
    if(isEmpty()){
        delete tail;
        head = tail = nullptr;
        return iMarker;
    }

    if(_size == 1){
        delete tail;
        tail = head;
        return iMarker;
    }

    for(node<T>* current = head; current->_next != nullptr; current = current->_next){
        if(current->_next->_data == iMarker){
            node<T>* temp = current->_next;
            current->_next = temp->_next;
            delete temp;

            return iMarker;
        }
    }
}

template<class T>
node<T>* List<T>::Search(const T &key){     //IN - search for this
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next){
        if(curr->_data == key){
            return curr;
        }
    }
//    return SearchList(head, key);
}

template<class T>
node<T>* List<T>::Search(const std::string &key){     //IN - search for this
    for(node<T>* curr = head; curr != nullptr; curr = curr->_next){
        if(curr->_data == key){
            return curr;
        }
    }
    throw "DOES NOT EXIST";
//    return SearchList(head, key);
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
//    return At(head, index);
}

template<class T>
node<T>* List<T>::Begin() const{
    return head;
}

template<class T>
node<T>* List<T>::End() const{
    return tail;
//    return LastNode(head);
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
