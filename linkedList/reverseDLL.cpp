#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Node
{

public:
    Node *next;
    // adding a back pointer to remmber the previous address
    Node *back;
    int data;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

void converArrToDLL(vector<int> &nums, Node *head)
{
    Node *prev = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        temp->back = prev;
        prev->next = temp;
        // moving the prev to the current temp;
        prev = temp; // temp = temp->next
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Node *reverseDLL(Node *head)
// {
//     stack<int> st;
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     Node *temp2 = head;

//     while (!st.empty())
//     {
//         int top = st.top();
//         st.pop();

//         temp2->data = top;

//         temp2 = temp2->next;
//     }
//     return head;
// }


Node *reverseDLL(Node *head){
    if(head==NULL) return head;

    Node *prev = NULL;
    Node * curreNode = head;
    while(curreNode != NULL){
        Node *forward = curreNode->next;
        curreNode->next = prev;
        prev=curreNode;
        curreNode=forward;
    }

    return prev;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = new Node(nums[0]);
    converArrToDLL(nums, head);
    print(head);

    cout << "aftrer reversal" << endl;

    Node *newNode = reverseDLL(head);
    print(newNode);

    return 0;
}