//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void printList(Node *head)
{
    if(head){
        while (head)
        {
            if(head->left)
                cout<<"-1 ";
            cout << head->data << " ";
            head = head->right;
        }
        cout << "\n";
    }
    else{
        cout << "Empty Tree!!";
    }
}


// } Driver Code Ends
//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
/*
    Steps: 
        1. First taking the sorted list after doing Inorder traversal
        2. Then creating a LL with the given sorted LL
        3. reutrn the new head as head
        4. Tc - O(n) + O(n)
        5. SC - O(n) + O(n)

*/
class Solution
{
public:
    // function tom storing the sorted data,because inorder gives sorted data
    void inOrder(Node *root, vector<int>&data){
        if(root == NULL) return;
        inOrder(root->left,data);
        data.push_back(root->data);
        inOrder(root->right,data);
    }
    Node *flattenBST(Node *root)
    {
        vector<int>data;
        inOrder(root, data);
        // creating a new node
        Node* newNode = new Node(data[0]);
        Node* curr = newNode; // to traverse the current pointer
        for(int i=1;i<data.size();i++){
            Node * temp = new Node(data[i]);
            // pointing the urren left to nULL, and right with the newly created temp
            // and updaing the curr
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        // after traversing the curr node willl bethe 
        // last node, and we have to poibnt the last node's left to null and right also to be null
        curr->left = NULL;
        curr->right = NULL;
        // returning the new head of the LL
        return newNode;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends