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
    assert(nodo != NULL);
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
    if(!list->head) return NULL;
    list->current=list->head;
    return (list->head->data);
}

void * lastList(List * list) {
    if(!list->tail) return NULL;
    list->current=list->tail;
    return (list->tail->data);
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}