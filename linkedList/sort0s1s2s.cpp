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

// int lengthOfLL(Node *head)
// {
//     int cnt = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         // cout << temp ->data << " ";
//         cnt++;
//         temp = temp->next;
//     }
//     return cnt;
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

Node *sortLL(Node *head)
{
    Node *temp = head; // taking temp becauxe we dont want to temper the original head

    // base case
    if (head == NULL || head->next == NULL)
    { // either empty or only one element, no need to sort
        return head;
    }

    Node *zeroHead = new Node(-1); // this will help us to get the new head
    Node *oneHead = new Node(-1);  // this will help us to get the new head
    Node *twoHead = new Node(-1);  // this will help us to get the new head

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    // now take temp notes whihc will help us to connect all similar nodea
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp; // or temp
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    // now its time to link them
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next; // if there is no two then it will point to the null
    two->next = NULL;
    Node * newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
   

}
int main()
{
    // Node *newNode = new Node(1);
    vector<int> nums1 = {2, 0, 1, 0, 0, 1, 2, 1, 2, 0};
    Node *head1 = convertArrToLL(nums1);
    print(head1);

    Node *newHead = sortLL(head1);
    print(newHead);

    return 0;
}