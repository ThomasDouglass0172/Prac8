#include "LinkedList.h"
#include "Node.h"
#include <iostream> 
#include <string> 
#include <limits> 
using namespace std; 

LinkedList::LinkedList(){
    head=nullptr; 
}


LinkedList::LinkedList(vector<int> sequence, int size){
    Node* temp = new Node(); 
    temp -> setData(sequence[0]);
    temp -> setNext(nullptr);
    head=temp; 

        for (int i=1; i<size; i++){
            Node* temp2 = new Node(); 
            temp ->setNext(temp2);
            temp2->setData(sequence[i]); 
            temp2->setNext(nullptr); 
            temp=temp2; 
        }
}


void LinkedList::addFront(int newItem){
    Node* temp = head; 
    head = new Node(); 
    head-> setData(newItem); 
    head-> setNext(temp); 
}


void LinkedList::addEnd(int newItem){
        Node* newNode = new Node(); 
        newNode-> setData(newItem); 
        newNode-> setNext(nullptr); 
   if (head==nullptr){
       head=newNode; 
   } 
   else{
       Node* temp = head; 
       while(temp->getNext() !=nullptr){
           temp= temp->getNext(); 
       }
       temp->setNext(newNode);
   }
} 


void LinkedList::addAtPosition(int position, int newItem){
    int count=0; 
        Node* newNode = new Node(); 
        newNode-> setData(newItem); 
        newNode-> setNext(nullptr); 
   if (position<1){
       //cout<<"outside range"<<endl; 
   } 

   else{
       Node* temp = head; 
       Node* previous = nullptr;
       while(count>0 || temp->getNext() != nullptr){
           previous = temp; 
           temp= temp->getNext();

           count--; 
       }
       if (temp->getNext() ==nullptr){
            cout<<"outside range"<<endl; 
       }
       previous->setNext(newNode);
       newNode->setNext(temp); 
   }
} 
int LinkedList::search(int item){
    int position=1; 
    Node* temp = head; 
    Node* previous = nullptr;
    while(temp->getData()!=item || temp->getNext() != nullptr){
        previous = temp; 
        temp= temp->getNext();
        position++; 

    }
    if (temp->getNext()==nullptr){
        cout<<"0 ";
        return 0; 
    }
    else{
        cout<<previous->getNext()<<" "<<temp->getData(); 
        return position;  
    }
}

   
void LinkedList::deleteFront(){
    Node* temp = head; 
    delete head; 
     head = temp->getNext();

}
void LinkedList::deleteEnd(){

    Node* temp = head; 
    Node* previous = new Node(); 
    while(temp->getNext() !=nullptr){
        previous=temp; 
        temp= temp->getNext(); 
    }
    previous->setNext(nullptr); 
    delete temp; 
}
void LinkedList::deletePosition(int position){
    int count=1; 
    Node* temp = head; 
    Node* previous = head; 
    if (position<1){
        cout<<"outside range"; 
    }
    if (position==1){
        delete head; 
        head=temp->getNext(); 
    }
    else{
    while(temp->getNext() !=nullptr || count!=position){
        previous=temp;  
        temp= temp->getNext(); 
        count++; 
    }
    if (temp->getNext() == nullptr){
        cout<<"outside range"; 
    }
    else{
        previous->setNext(temp->getNext()); 
        delete temp; 
        }
    }
}

int LinkedList::getItem(int position){
int count=1; 
if (position<1){
    cout<<std::numeric_limits < int >::max()<<" "; 
    return std::numeric_limits < int >::max(); 
}
Node* temp = head; 
while(count!=position || temp->getNext() != nullptr){
    temp= temp->getNext();
    count++; 

}
if (temp->getNext() == nullptr){
    cout<<std::numeric_limits < int >::max()<<" "; 
    return std::numeric_limits < int >::max(); 
}
else{
    cout<<temp->getData()<<" "; 
    return temp->getData();  
}
}


void LinkedList::printItems(){
    Node* temp = head; 
while(temp->getNext() != nullptr){
    cout<<temp->getData()<<" ";
    temp= temp->getNext();
}
    cout<<temp->getData(); 
}