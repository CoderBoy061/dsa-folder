#include <iostream>
#include <string>
#include <vector>
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

Node *convertArrToLL(vector<int> &nums)
{

    // a new node will be created for 12, because 12 is the first element
    Node *head = new Node(nums[0]);
    // now lets take a mover
    Node *mover = head;

    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        // cout << temp ->data << " ";
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int serachInLinkedlist(Node *head, int target)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main()
{
    // Node *newNode = new Node(1);
    vector<int> nums = {12, 5, 4, 7, 8};
    Node *head = convertArrToLL(nums);
    // cout << head->data <<endl;

    // traverse a linkedlist

    Node *temp = head; // making a copy of head, because we dont want to loose thead

    // while(temp != NULL){
    //     cout << temp ->data << " ";
    //     temp = temp->next;
    // }

    // cout << lengthOfLL(head);

    cout << serachInLinkedlist(head, 12);
    return 0;
}