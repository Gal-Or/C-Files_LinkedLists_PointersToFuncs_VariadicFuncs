#include "linkedList.h"
#include "Object.h"

BOOL L_init(List* pList)
{// create empty list to the pointer pList
	if (pList == NULL) return False;

	pList->head.next = NULL;
	return True;
}

//pNode: pointer to node BEFORE the place for the new one
Node* L_insert(Node* pNode, Object* Value)
{
	Node* tmp;
	if (!pNode) return NULL;
	tmp = (Node*)malloc(sizeof(Node));
	if (tmp != NULL) {
		tmp->value = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}

//pNode:pointer to node BEFORE the node to be deleted
BOOL L_delete(Node* pNode)
{
	Node* tmp;
	if (!pNode || !(tmp = pNode->next)) return False;
	pNode->next = tmp->next;
	free(tmp);
	return True;
}

BOOL L_free(List* pList)
{// free all memory of the list that pointerd by pList
	Node* tmp;

	if (!pList) return False;

	for (tmp = &(pList->head); L_delete(tmp); );
	free(pList);
	return True;
}

