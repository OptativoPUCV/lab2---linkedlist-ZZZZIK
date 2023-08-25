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
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* movies= (List*) malloc(sizeof(List));
  
  movies->head=NULL;
  movies->current=NULL;
  movies->tail=0;
  return movies;
}

void * firstList(List * list) {
  if (list->head==NULL) return NULL;
  list->current = list->head;
  
  return list->current->data;
}

void * nextList(List * list) {
  if (list->current==NULL || list->current->next==NULL) return NULL;
  list->current=list->current->next;
  return list->current->data;
  
}

/*
Programe las funciones `void * lastList(List * list)` y `void * prevList(List * list)`.
   * La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. 
   * La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
*/

void * lastList(List * list) {
  if (list->tail==NULL) return NULL;
  list->current = list->tail;
  
  return list->current->data;
  
}

void * prevList(List * list) {
  if (list->current==NULL || list->current->prev==NULL) return NULL;
  list->current=list->current->prev;
  return list->current->data;
}

/*
4. Programe la función `void pushFront(List * list, void * data)`, la cual agrega un dato al comienzo de la lista. 
  > Puede utilizar la función `Node* createNode(void * data)` la cual crea,   incializa y retorna un nodo con el dato correspondiente. 

*/

void pushFront(List * list, void * data) {
  Node * new_node= createNode(data);
  if (data==NULL) return;
  list->current=list->head;
  list->current->next=new_node;
  list->head= new_node;
  return;
  

  
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