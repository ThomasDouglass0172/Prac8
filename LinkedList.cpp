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
    int count=position; 
    Node* newNode = new Node(); 
    newNode-> setData(newItem); 
    newNode-> setNext(nullptr); 
    Node* temp = head; 
    Node* previous = nullptr;
    Node* behind =nullptr; 
    if (position<=1){
        addFront(newItem); 
        return; 
    }
   else{

       while(temp->getNext() != nullptr){
           if (temp->getNext() == nullptr){
               cout<<count; 
               addEnd(newItem);
               return; 
           }
           if (count==0){

               break; 
           }

           behind=previous;
           previous = temp; 
           temp= temp->getNext();

           count--; 
       }
       if (count>=1){
           previous->setNext(newNode);
           newNode->setNext(temp);
           return;
       }
       behind->setNext(newNode);
       newNode->setNext(previous); 
   }
} 
int LinkedList::search(int item){
    int position=1; 
    Node* temp = head; 
    while(temp->getNext() != nullptr){
        if (temp->getData()==item){
            break; 
        }
         temp= temp->getNext();
         position++; 
    }
    if (temp->getNext()==nullptr){
        cout<<"0 ";
        return 0; 
    }
    else{
        cout<<position<<" ";
        return position;  
    }
    return position;
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
    while(temp->getNext() !=nullptr){
        if (count==position){
            break; 
        }
        previous=temp;  
        temp= temp->getNext(); 
        count++; 
    }
    if (temp->getNext() == nullptr){
        if (count==position){
            deleteEnd(); 
        }
        else{
        cout<<"outside range";
        } 
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
while( temp->getNext() != nullptr){
    if (count==position){
        break;
    }
    temp= temp->getNext();
    count++; 

}
if (temp->getNext() == nullptr){
    if (count==position){
    cout<<temp->getData()<<" "; 
    return temp->getData();
    }
    else{
    cout<<std::numeric_limits < int >::max()<<" "; 
    return std::numeric_limits < int >::max(); 
    }

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

LinkedList::~LinkedList(){
Node* current = head;
while( current != 0 ) {
    Node* next = current->getNext();
    delete current;
    current = next;
}
head = 0;
}