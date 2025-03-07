/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
// TC - O(n), SC-O(1)
// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {


//     // taking a temp node for traversal
//     TreeNode *temp = root;
//     // initializing the both variable -1
//     int succ = -1;
//     int pred = -1;

//     // whoil
//     while(temp != NULL && temp->data != key){

//         // check if the current data is greater than key
//         if(temp->data  > key){
//             succ = temp->data;
//             temp = temp->left;
//         }else{
//             pred = temp->data;
//             temp = temp->right;
//         }
//     }
//     // if the temp is null
//     if(temp == NULL) return {pred,succ};
//     // now get the pred
//     TreeNode *leftTree = temp->left;
 
//     // taking the maxium from the left part
//     while(leftTree !=NULL){
//         pred = leftTree->data;
//         leftTree = leftTree->right;
//     }

//     TreeNode *rightTree = temp->right;
//     // talking the minimum from the right sub tree
//     while(rightTree !=NULL){
//         succ = rightTree->data;
//         rightTree = rightTree->left;
//     }

//     return {pred,succ};

// }