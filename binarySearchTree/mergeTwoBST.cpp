/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// class Solution {
//   public:
//     // Function to return a list of integers denoting the node
//     // values of both the BST in a sorted order.
//     void inOrder(Node* root, vector<int>& in) {
//         if (root == NULL)
//             return;
//         inOrder(root->left, in);
//         in.push_back(root->data);
//         inOrder(root->right, in);
//     }
//     vector<int> mergeArrays(vector<int>& in1, vector<int>& in2) {
//         vector<int> ans(in1.size() + in2.size());
//         int i = 0, j = 0, k = 0;
    
//         while (i < in1.size() && j < in2.size()) {
//             if (in1[i] < in2[j]) {
//                 ans[k++] = in1[i];
//                     i++;
//                 } else {
//                     ans[k++] = in2[j];
//                     j++;
//                 }
//             }
//         while (i < in1.size()) {
//                 ans[k++] = in1[i];
//                 i++;
//             }
//         while (j < in2.size()) {
//                 ans[k++] = in2[j];
//                 j++;
//             }
//             return ans;
//         }
//         Node * mergedBst(int s,int e, vector<int>& in){
//             if(s > e) return NULL;
    
//             int mid = s + (e-s)/2;
//             Node* newNode = new Node(in[mid]);
//             newNode->left = mergedBst(s,mid-1,in);
//             newNode->right = mergedBst(mid+1,e,in);
//             return newNode;
//         }
//     Node * merge(Node *root1, Node *root2) {
//             vector<int> in1, in2;
//             inOrder(root1, in1);
//             inOrder(root2, in2);
    
//             vector<int> mergedArray = mergeArrays(in1, in2);
//             int s = 0;
//             int e = mergedArray.size()-1;
//             return mergedBst(s,e,mergedArray);
//     }
// };

