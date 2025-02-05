#include <iostream>
#include <string>
#include <vector>
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

Node *removeHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = temp->next;
    head->back = NULL;
    delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    // temp->back = NULL;
    prev->next = NULL;
    temp->back = NULL;
    // temp->back = NULL;
    delete temp;
    return head;
}

Node *removeKth(Node *head, int k)
{
    // check for NULL

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    if (k == 1)
    {
        // means we need to delete the head

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node *temp = head;

    while (temp->next != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            Node *prev = temp->back;
            temp->next->back = prev;
            temp->back = NULL;
            temp->next = NULL;
            delete temp;
        }
    }
    temp = temp->next;
    return head;
}

// insert at the head
Node *insertHead(Node *head, int val)
{
    if (head == nullptr)
        return new Node(val);

    Node *temp = new Node(val);

    temp->next = head;
    head->back = temp;

    return temp;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == nullptr)
    {
        return insertHead(head, val);
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(val);
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = temp;
    temp->back = newNode;
    return head;
}

Node *insertBeforeKth(Node *head, int val, int k)
{
    if (k == 1)
    {
        return insertHead(head, val);
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(val);
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = temp;
    temp->back = newNode;
    return head;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = new Node(nums[0]);
    converArrToDLL(nums, head);
    cout << "before delete" << endl;
    print(head);

    // cout << "after delete" << endl;
    // Node *newHead = removeHead(head);
    // print(newHead);

    // cout << "after delete the tail" << endl;
    // Node *newHead = removeTail(head);
    // print(newHead);
    // cout << "after delete the kth element" << endl;
    // Node *newHead = removeKth(head, 4);
    // print(newHead);
    cout << " afetr insertion at before head" << endl;
    // Node *newHead = insertHead(head, 40);
    // print(newHead);
    // cout << " afetr insertion at before tail" << endl;
    // Node *newHead = insertBeforeTail(head, 33);
    // print(newHead);
    cout << " afetr insertion at before kth element" << endl;
    Node *newHead = insertBeforeKth(head, 40, 3 );
    print(newHead);

    return 0;
}