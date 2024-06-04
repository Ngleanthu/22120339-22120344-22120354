#include "Linklist.h"
List* makenode(State* state)
{
	List* p = new List;
	p->_state = state;
	p->next = nullptr;
	return p;
}
void push_front(List*& head, State* state)
{
	if (!head)
	{
		head = makenode(state);
		return;
	}
	List* p = makenode(state);
	p->next = head;
	head = p;
}
void pop_front(List*& head)
{
	if (!head)
	{
		return;
	}
	List* tmp = head;
	head = head->next;
	delete tmp;
}