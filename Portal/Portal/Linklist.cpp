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
Clist* makenode(Course course)
{
	Clist* p = new Clist;
	p->_course = course;
	p->next = nullptr;
	return p;
}
void push_front(Clist*& head, Course course)
{
	if (!head)
	{
		head = makenode(course);
		return;
	}
	Clist* p = makenode(course);
	p->next = head;
	head = p;
}
bool del(Clist*& head , std::string id)
{
	if (!head)
	{
		return 0 ;
	}
	if (head->_course.courseid == id)
	{
		Clist* k = head;
		head = head->next;
		delete k; 
	}
	Clist* tmp = head;
	while (tmp->next != nullptr && tmp->next->_course.courseid != id)
	{
		tmp = tmp->next;
	}
	if (tmp->next->_course.courseid == id)
	{
		Clist* k = tmp->next;
		tmp->next = tmp->next->next;
		delete k; 
		return 1;
	}
	return 0; 

}

 
