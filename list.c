#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * nodo = (Node *)malloc(sizeof(Node));
    nodo->data = data;
    nodo->prev = NULL;
    nodo->next = NULL;
    return nodo;
}

List * createList() {
    List * l = (List *) malloc (sizeof(List));
    l->head = NULL;
    l->current = NULL;
    l->tail = NULL;
     return l;
}

void * firstList(List * list) {
    if(!list->head) return NULL;
    list->current=list->head;
    return (list->head->data);
}

void * nextList(List * list) {
    if (list->current == NULL) return NULL;
    if (list->current->next == NULL) return NULL;
    
    list->current = list->current->next;
    return (list->current->data);
}

void * lastList(List * list) {
    if(!list->tail) return NULL;
    list->current=list->tail;
    return (list->tail->data);
}

void * prevList(List * list) {
    if (list->head == NULL) return NULL;
    if (list->current == NULL) return NULL;
    if (list->current->prev == NULL) return NULL;
    
    list->current = list->current->prev;
    return (list->current->data);
}

void pushFront(List * list, void * data) {
    Node * n = createNode(data);
    n->next = list->head;
    if(list->tail == NULL)
        list->tail = n;
    list->head = n;
    n->prev = NULL;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node * nuevo = createNode(data);
    Node * aux = createNode(data);


    if(list->current == list->tail)
    {
        list->current->next = nuevo;
        nuevo->prev = list->tail;
        list->tail = nuevo;
    }
    else
    {
        aux = list->current->next;
        list->current->next = nuevo;
        nuevo->next = aux;
        nuevo->prev = list->current;
    }
        
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    Node * aux = createNode(list->current->data);
    if(list->head == list->current)
    {
        aux = list->current->data;
        aux->prev=NULLl;
        list->head->next = aux;
        list->head = list->head->next;

        free(list->current);

        //list->current = list->head;
        list->head->prev = NULL;
        return aux->data;
    }
    else
    {
        list->current->prev = list->current->next;
        list->current->next = list->current->prev;

        free (list->current);    
        return aux;        
    }
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}