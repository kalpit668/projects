//dstack.h file
//Sharma, Kalpit
//ksharma12
#ifndef dstack_h
#define dstack_h


class Dstack{
private:
    class Node {
    public:
    double data; // data stored in the node
    Node* next; 
    Node(double d) {
    data = d;
    next = nullptr;
    }
// Destructor for the node (currently empty)
~Node() { }
};
    
public:
//All the functions and methods of the stack
    Node* head;
    Dstack();
    ~Dstack();
    void push(double x);
    double pop();
    int size();
    bool empty();
    int count = 0;
   
};


#endif