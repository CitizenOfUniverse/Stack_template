/*
* node.h - Contains descriptor of the "helper" class node
*/

// Descriptor of the "helper" class node. One node is one element of the stack
template<class T>
class node{
	node* prev;//Pointer to the previous node
	T data;//Field for useful data of node
public:
	node* getPrev();//"Get" method for "prev" field
	T getData();//"Get" method for "data" field
	node(node*, T);//Class constructor. Initialises both private fields.
};

// node class constructor
template<class T> node<T>::node(node* prev, T data) {
	this->prev = prev;
	this->data = data;
}
// "Get" method for field prev of class node
template<class T> node<T>* node<T>::getPrev() {
	return this->prev;
}
// "Get" method for field data of class node
template<class T> T node<T>::getData() {
	return this->data;
}
