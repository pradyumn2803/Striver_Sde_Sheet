/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<limits.h>
TreeNode<int>* buildTree(int &i,int bound,vector<int> &preorder)
{
    if(i==preorder.size() || preorder[i]>bound) return NULL;
    TreeNode<int>* root=new TreeNode<int>(preorder[i++]);
    root->left=buildTree(i,root->data,preorder);
    root->right=buildTree(i,bound,preorder);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i=0;
    return buildTree(i,INT_MAX,preOrder);
}