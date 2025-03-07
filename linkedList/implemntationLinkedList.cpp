#include <iostream>
#include <string>
using namespace std;

// individual node class
class Node
{
public:
    int data;   // data
    Node *next; // address of next node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int main()
{
    Node *newNode = new Node(1);
    return 0;
}