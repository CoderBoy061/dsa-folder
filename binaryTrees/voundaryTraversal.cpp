//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    return new Node(val);
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
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

// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
/*
        Time Complexity: O(n) (each node is visited once).

        Space Complexity: O(h) (recursion stack space, where h is the height of the tree).

*/
class Solution
{
public:
    // left subtree traversal
    void traverseLeft(Node *root, vector<int> &ans)
    {
        // check for blank data
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return; // means thease are the leaf nodes

        ans.push_back(root->data); // pusing the current left node;
        // always check for the left part first because this is for left subtree
        if (root->left) // if left is not null only then travese into the right part
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }
    // leaf nodes traversal of the both subtree
    void traverseLeaf(Node *root, vector<int> &ans)
    {
        // bvase case
        if (root == NULL)
            return; // sdimply return from here

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data); // if there is not left and no right part, means we are standing in the leaf node
            return;                    // after pushing the node, simply return from here
        };
        // now travserse the right part and the left part
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    void traverseRight(Node *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return; // means we are trying to traverse the leaf node

        // nowe check if the right part exists then fgo to the right, otherwise go to the left part of thr right subtree
        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data); // if we come back means we are in the current right node from the bottom
    }
    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> ans;

        // base case
        if (root == NULL)
            return ans;

        ans.push_back(root->data); // first puting the root->data;
        // now we have to traverse the left part of the binary tree

        traverseLeft(root->left, ans);
        // now traverse the leaf nodes, so the leaf npdes can exists in left subtree and alos right sub tree,
        // so we have to call for both part
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        traverseRight(root->right, ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends