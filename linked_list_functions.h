#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream>
#include <cassert>
using namespace std;

template <typename ITEM_TYPE>
struct node
{
public:
    node(){
        next = NULL;
        _item = ITEM_TYPE();
    }
    node(ITEM_TYPE item){
        next = NULL;
        _item = item;
    }

    ITEM_TYPE _item;        //ATT - item in list
    node<ITEM_TYPE>* next;  //ATT - next item in list


};

template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,  //IN - list head
                            ITEM_TYPE key);         //IN - val to search for


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,       //IN - list head
                              node<ITEM_TYPE>* prevToThis); //IN - prev pointer


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,     //IN - list head
                            ITEM_TYPE insertThis);       //IN - val to insert


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(
                              node<ITEM_TYPE> *afterThis,   //IN - node ptr
                             ITEM_TYPE insertThis);         //IN - val to ins

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,      //IN - list head
                              node<ITEM_TYPE>* beforeThis,  //IN - ins before
                              ITEM_TYPE insertThis);        //IN - val to ins

template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,                 //IN - list head
                     node<ITEM_TYPE>* deleteThis);           //IN - ptr to del

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head);       //IN - list head

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head);                 //IN - list head

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head,         //IN - list head
              int pos);                      //IN - position to ret val

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,    //IN - list head
                             ITEM_TYPE item,              //IN - val to ins
                             bool ascending=true);        //IN - how to sort

template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertSorted_and_add(
                                    node<ITEM_TYPE>* &head,//IN - list head
                                    ITEM_TYPE item,        //IN - val to ins
                                    bool ascending=true);  //IN - how to sort

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head,        //IN - list head
                              ITEM_TYPE item,                //IN - val to ins
                               bool unique,                  //IN - if unique
                              bool ascending=true);          //IN - how to sort
template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head);          //IN - list head


template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,  //IN - list head
                            ITEM_TYPE key){         //IN - val to search for

}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,     //IN - list head
                             ITEM_TYPE insertThis){      //IN - val to insert

}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(                              node<ITEM_TYPE> *afterThis,  //IN - ptr
ITEM_TYPE insertThis){       //IN - ins after ptr
// calls insert head and use afterthis-> next as the head
return _InsertHead(afterThis->next, insertThis);
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,       //IN - list head
                               node<ITEM_TYPE>* beforeThis,  //IN - ptr
                              ITEM_TYPE insertThis){         //IN - ins be4 ptr

}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,        // IN - list head
                               node<ITEM_TYPE>* prevToThis){ // IN - ptr

}

template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,            // IN - list head
                      node<ITEM_TYPE>* deleteThis){     // IN - ptr to delete

}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head){ // IN - list head


}

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head){ // IN - list head

}

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head,        // IN - list head
              int pos){                     // IN - list position

}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, // IN - list head
                                      ITEM_TYPE item,         // IN - val ins
                                      bool ascending){        // IN - sort type

}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,  // IN - list head
                               ITEM_TYPE target,        // IN - val to ins
                               bool ascending){         // IN - sort type

}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, // IN - list head
                               ITEM_TYPE item,        // IN - val to ins
                               bool unique,           // IN - if unique
                               bool ascending){       // IN - sort type

}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){ // IN - list head

}

#endif // LINKED_LIST_FUNCTIONS_H
