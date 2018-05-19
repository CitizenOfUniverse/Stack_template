/*
* main.cpp - Main project file. Contains only main function 
*/

#include <iostream>
//Preventing double including of file "stack.h"
#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif

using std::cout;

int main(){
	stack<double> stck;
	stck.push(2.12);
	stck.push(225.814);
	cout << stck.pop();
	return 0;
}
