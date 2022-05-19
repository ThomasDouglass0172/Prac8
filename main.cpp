#include "LinkedList.h"
#include "Node.h"
#include <vector>
#include <iostream> 
#include <string> 
#include <algorithm> 
#include <limits>
using namespace std; 


int main(){

vector<int> sequence; 
int num=0; 
string function; 
int parameter1; 
int parameter2; 

while(cin>>num){
    sequence.emplace_back(num); 
}
cin.clear(); 
cin>>function>>parameter1>>parameter2;  


int size = sequence.size();  

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