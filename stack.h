/*
* stack.h - Contains descriptor of the class stack
*/

// Preventing double including of file "node.h"
#ifndef _NODE_H_
#define _NODE_H_
#include "node.h"
#endif
// Descriptor of the class stack - main of the project
template<class T> class stack{
	node<T>* top;//Pointer to the top node
	int size;//Size of the stack
public:
	stack();//Class constructor. Initialises both private fields
	~stack();//Class destructor
	T pop();///Method needed to delete the top of stack and return its currents useful data. If the stack is already empty, method throws an exeption (type of it is C-string).
	void push(T);// Method needed to add ("push") data to the top of stack. If there was an error in allocating memory, method throws an exeption (type of it is C-string).
};

// stack class constructor. Initialises both private fields with standart constants
template<class T> stack<T>::stack() {
	size = 0;
	top = nullptr;
}
// stack class destructor
template<class T> stack<T>::~stack() {
	//Memory for every node was allocated separately from every other one,
	//so we also need to delete nodes one by one
	for (int i = 0; i < this->size; i++) {
		node<T>* old_top = this->top;//Extracting top node from the stack
		this->top = this->top->getPrev();//Setting a new top in a stack
		delete old_top;//Deleting old top
	}
}
// Method needed to add ("push") data to the top of stack
template<class T> void stack<T>::push(T data) {
	this->top = new node<T>(this->top, data);//Allocating memory for a new node and initialising its fields
	if (this->top == NULL) {//If memory wasn't allocated, method throws an exeption
		throw "ERROR! Couldn't allocate memory for an element.";
	}
	this->size++;//Incrementing size of the stack
}
// Method needed to delete the top of stack and return its currents useful data
template<class T> T stack<T>::pop() {
	if (this->size == 0) {//If the stack is empty, there is no to return. So, method throws an exeption
		throw "ERROR! The stack is already empty.";
	}
	else {
		T r_data = this->top->getData();//Saving data of the old top needed to return
		node<T>* old_top = this->top;//Extracting old top from the stack
		this->top = this->top->getPrev();//Setting a new top of the stack
		this->size--;//Decreasing size
		delete old_top;//Deallocating memory for the top node of the stack
		return r_data;//Returning useful data of the old top
	}
}
