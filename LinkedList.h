#pragma once
#include "ADTList.h"
#include "Object.h"
/*
En esta clase se representa lo que sería una implementacion de
lista enlazada con nodos de un solo enlace.

Los miembros de esta clase Node son:
->Next : Objeto que apuntará al siguiente nodo.
->Data : Aquí almacenaremos datos en nuestro nodo.
*/
class LinkedList : public ADTList{
    class Node{
    public:
        Object* data;
        Node* next;
        Node(Object*);
        ~Node();
    };
    Node* head;

public:
     LinkedList();
     ~LinkedList();
     bool insert(Object*,int);
     Object* remove(int) ;
     Object* first()const;
     Object* last()const;
     void clear();
     int indexOf(Object*)const;
     Object* get(int)const;
     bool isEmpty()const;
     bool isFull()const;

};
