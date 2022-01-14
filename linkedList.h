#pragma once
#include "object.h"
typedef struct node
{
	Object* value;
	struct node* next;

}Node;

typedef struct {
	Node head;
}List;

typedef enum { False, True }BOOL;

BOOL L_init(List* pList);
Node* L_insert(Node* pNode, Object* Value);
BOOL L_delete(Node* pNode);
BOOL L_free(List* pList);