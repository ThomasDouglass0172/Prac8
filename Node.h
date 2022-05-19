#ifndef NODE_H
#define NODE_H
#include <iostream> 

class Node {

public:
Node(); 
int getData();
void setData(int data);
Node* getNext(); 
void setNext(Node* next);



private: 
int data=0;  
Node* next =nullptr;

};

#endif