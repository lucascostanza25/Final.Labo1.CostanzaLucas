/*
 * LinkedList.h
 *
 *  Created on: 14 nov. 2021
 *      Author: Lucas
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct Node
{
    void* pElement;                 //Puntero al elemento con el cual se va a rellenar el nodo (persona, empleado, etc.)
    struct Node* pNextNode;         //Puntero que apunta al siguiente nodo de la lista
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;				//Puntero que apunta al inicio de la lista
    int size;                       //Tamaño de la lista - Cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;

LinkedList* ll_newLinkedList(void);
LinkedList* ll_sublist(LinkedList* this, int from, int to);
LinkedList* ll_clone(LinkedList* this);
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*));
Node* test_getNode(LinkedList* this, int nodeIndex);
void* ll_get(LinkedList* this, int index);
void* ll_pop(LinkedList* this, int index);
int ll_len(LinkedList* this);
int test_addNode(LinkedList* this, int nodeIndex, void* pElement);
int ll_add(LinkedList* this, void* pElement);
int ll_set(LinkedList* this, int index, void* pElement);
int ll_remove(LinkedList* this, int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this, LinkedList* this_2);
int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order);
int ll_map(LinkedList* this, int (*pFunc)(void*));

#endif /* LINKEDLIST_H_ */
