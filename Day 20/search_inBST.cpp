/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL) return false;
    while(root && root->data!=x)
    {
        root=(root->data<x)?root->right:root->left;
    }
    return (root==NULL)?false:true;
}