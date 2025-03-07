#include <iostream>
#include <string>
#include <vector>
#include <stack>
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

bool isPalindrome(Node *head)
{
    stack<int> st;
    Node *temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    Node *temp2 = head;

    while(temp2 != NULL){
        int top = st.top();

        if(top == temp2->data){
            return true;
        }else{
            return false;
        }
    }
    return false;
}
int main()
{
    // Node *newNode = new Node(1);
    vector<int> nums1 = {2, 0, 1, 0, 0, 1, 2, 5, 2, 0};
    Node *head1 = convertArrToLL(nums1);
    print(head1);
    bool ans = isPalindrome(head1);
    cout<<ans << endl;

    // Node *newHead = removeNth(head1, 3);
    // print(newHead);

    return 0;
}