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

// int serachInLinkedlist(Node *head, int target)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == target)
//         {
//             return 1;
//         }
//         temp = temp->next;
//     }
//     return 0;
// }

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << " " << endl;
}
Node *sumTwoLL(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp1->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    // check for leftover carry
    if(carry){
        Node * newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}
int main()
{
    // Node *newNode = new Node(1);
    vector<int> nums1 = {1, 2, 3, 4, 5};
    Node *head1 = convertArrToLL(nums1);
    print(head1);
    vector<int> nums2 = {6, 7, 8, 9, 5};
    Node *head2 = convertArrToLL(nums2);
    print(head2);

    Node *sumNode = sumTwoLL(head1, head2);
    print(sumNode);

    return 0;
}