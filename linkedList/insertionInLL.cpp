#include <iostream>
#include <vector>
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
// this will convert the array to LL
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
// traverse the entire LL
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << " " << endl;
}

// insert new element at the head

Node *insertAtHead(Node *head, int el)
{

    // let's create a new element
    Node *temp = new Node(el); // created a node

    temp->next = head;
    head = head->next;

    return temp; // temp will be our new head
}

// this will insert the element at the tail
Node *insertAtTail(Node *head, int el)
{

    if (head == NULL)
        return new Node(el);
    Node *temp = head;

    // now traverse untill the
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    // if this reaches into null then we are att the tail
    Node *newNode = new Node(el); // created a new node
    // I know my tail, so I just need to point the temp' next to the current created node
    // temp = temp->next;
    temp->next = newNode;
    return head;
}

Node *insertAtKthEl(Node *head, int val, int k)
{

    // if head is null, then simply check the k, if it is 1, then simply add a new node and return its head
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(val);
        }
    }
    // means we have to insert the element at the first position
    if (k == 1)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = head->next;

        return temp;
    }

    // now check fo others position
    int cnt = 0;
    Node *temp = head;

    while (head != NULL)
    {
        // increase the cnt;
        cnt++;

        // here we have to do the job
        if(cnt == k-1){
            Node * newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }

        temp = temp->next;

    }
    return head;
}
int main()
{
    vector<int> nums = {1, 2, 5, 4, 7, 8};

    Node *head = convertArrToLL(nums);
    traversal(head);

    // after insertion
    // Node *newHead = insertAtHead(head, 6);
    // traversal(newHead);

    // after insertion at the tail
    // Node *newTail = insertAtTail(head, 9);
    // traversal(newTail);

    // Node *newHead = insertAtKthEl(head,10, 8);
    // traversal(newHead);
    return 0;
}