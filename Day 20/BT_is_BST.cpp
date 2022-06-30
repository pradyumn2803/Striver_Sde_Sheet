/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/
#include<limits.h>
bool check(int lower,int upper,BinaryTreeNode<int> *root)
{
    if(root==NULL) return true;
    if(root->data<lower || root->data>upper) return false;
    return (check(lower,root->data,root->left) && check(root->data,upper,root->right));
}
bool validateBST(BinaryTreeNode<int> *root) {
    return check(INT_MIN,INT_MAX,root);
}