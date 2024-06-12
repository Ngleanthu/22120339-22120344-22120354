#pragma once
#include"State.h"
#include<iostream>
struct List
{
	State* _state;
	List* next;
};
List* makenode(State* state);
void push_front(List*& head, State* state);
void pop_front(List*& head);



