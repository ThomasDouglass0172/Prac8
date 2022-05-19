#include "Node.h"

using namespace std;

Node::Node(){
setData(0);
setNext(nullptr); 
}

int Node::getData(){
return data; 
}
void Node::setData(int data){
this->data=data; 
}
Node* Node::getNext(){
return next; 
}
void Node::setNext(Node* next){
this->next=next; 
}