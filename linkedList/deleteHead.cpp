#include <iostream>
#include <vector>
#include<string>
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
// delete the head from the node
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head; // making a copy of the temp
    // temp->next=head;
    head = head->next;
    // this will delete the temp variable from the memory
    delete temp;

    return head;
}

// delete the tail from the linkedList

Node *deletetail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        // just update the postion of temp untill it becomes null
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node *deleteKthElement(Node *head, int k)
{

    // base case incase the LL is empty
    if (head == NULL)
        return head;
    // if the k is 1, so simply delete the head of the LL
    if (k == 1)
    {
        // means delete the head
        Node *temp = head;
        // moving the head
        head = head->next;
        delete temp;
        return head;
    }

    // now lets address the other cases
    int cnt = 0;
    Node *temp = head; // copying the head to preserve
    Node *prev = NULL; // initailly the prev will be null

    while (temp != NULL)
    { // means we are still in a vaild LL

        cnt++;

        if (cnt == k)
        { // means the count reaches the kth position

            // do something
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        // remember the prev
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteEl(Node *head, int el)
{
    if (head == NULL)
        return head;

    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL){

        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    // Node *newNode = new Node(1);
    vector<int> nums = {1, 2, 5, 4, 7, 8};
    Node *head = convertArrToLL(nums);
    // before deletion
    traversal(head);
    // after deletion
    // getitng the new head from the function
    // Node *newHead = deleteHead(head);
    // traversal(newHead);

    // after deleeing the tail
    // Node *newHead = deletetail(head);

    // Node *kthDelete = deleteKthElement(head, 5);
    Node *kthDelete = deleteEl(head, 8);
    // after deletion
    cout<< "after deletion" << endl;
    traversal(kthDelete);

    return 0;
}