//dstack.cpp file
//Sharma, Kalpit
//ksharma12
#include "dstack.h"
#include <iostream>
using namespace std;

Dstack::Dstack(){ // Constructor
    head = nullptr;
}

Dstack::~Dstack(){ // Destructor
    while (head != nullptr)
    {
    Node* temp = head;
    head = head->next;
    delete temp;
    } 
}
void Dstack::push(double x){ //Push in stack
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    count++;
}

double Dstack::pop(){ // Pop out of the stack
    if (!empty())
    {
        Node* temp = head;
        head = head->next;
        double x = temp->data;
        delete temp;
        count--;
        return x;
    }
    throw "Error: Invalid expression.";
}
 bool Dstack::empty(){ // Check for empty stack
    if (head != nullptr)
    {
        return false;
    }
    return true;
 }
int Dstack::size(){ // Size of the stack
   return count;
}