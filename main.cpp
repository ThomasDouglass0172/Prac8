#include "LinkedList.h"
#include "Node.h"
#include <iostream> 
#include <string> 
#include <algorithm> 
#include <limits>
#include <array>
using namespace std; 


int main(){

int sequence[100]; 
int num=0; 
string function; 
int parameter1; 
int parameter2; 
int size =0; 

while(cin>>num){

    sequence[size]=num; 
    size++; 

}
cin.clear(); 
cin>>function>>parameter1>>parameter2;  

LinkedList linky(sequence, size) ;

if(function == "AF"){
    linky.addFront(parameter1); 
}
if(function == "AE"){
    linky.addEnd(parameter1);    
}
if(function == "AP"){
    linky.addAtPosition(parameter1, parameter2); 
}
if(function == "S"){
    linky.search(parameter1); 
}
if(function == "DF"){
    linky.deleteFront(); 
}
if(function == "DE"){
    linky.deleteEnd(); 
}
if(function == "DP"){
    linky.deletePosition(parameter1); 
}
if(function == "GI"){
    linky.getItem(parameter1); 
}

linky.printItems(); 
















return 0; 
}