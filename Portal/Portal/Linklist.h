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

struct Course
{
	std::string courseid, coursename, classname, teachername, numofcredit, maxstudents, dayofweek, sessions;
};
struct Clist
{
	Course _course;
	Clist* next;
};
Clist* makenode(Course course);
void push_front(Clist*& head, Course course);
bool del(Clist*& head, std::string id);


