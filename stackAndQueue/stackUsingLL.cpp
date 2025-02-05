#include <iostream>
using namespace std;

class Stack
{

public:
    Stack *top;
    int data;
    Stack *next;
    // this will only create a new node
    Stack(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    void push(int val)
    {
        Stack *temp = new Stack(val);
        temp->next = top;
        top = temp;
    }

    int top(){

        return top->data;
    }

    int pop(){
        Stack *temp = top;

        
    }
};

int main()
{

    return 0;
}