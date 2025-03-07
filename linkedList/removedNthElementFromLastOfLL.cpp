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

// TC - O(len of LL)
// SC- O(1)
Node *removeNth(Node *head, int n)
{
    // we can follow the Fast and Slow pointer approach
    Node *fast = head;

    // moving the fast to the nth point/index
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // if the fast s null return from ghere
    if (fast == NULL)
    {
        // means we are taking the fiest elemnt to delete
        return head->next;
    }

    Node *slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *nodetoDelete = slow->next;
    slow->next = slow->next->next;
    delete nodetoDelete;
    return head;
}
int main()
{
    // Node *newNode = new Node(1);
    vector<int> nums1 = {2, 0, 1, 0, 0, 1, 2, 5, 2, 0};
    Node *head1 = convertArrToLL(nums1);
    print(head1);

    Node *newHead = removeNth(head1, 3);
    print(newHead);

    return 0;
}