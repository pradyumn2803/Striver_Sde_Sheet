/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<limits.h>
class Node
{
public:
    int min_val,max_val,size;
    Node(int min_val,int max_val,int size)
    {
        this->min_val=min_val;
        this->max_val=max_val;
        this->size=size;
    }
};

Node largestBSTfunc(TreeNode<int>* root)
{
    if(root==NULL) return Node(INT_MAX,INT_MIN,0);
    
    auto left=largestBSTfunc(root->left);
    auto right=largestBSTfunc(root->right);
    
    if(left.max_val<root->data && root->data<right.min_val)
        return Node(min(root->data,left.min_val),max(root->data,right.max_val),left.size+right.size+1);
    else return Node(INT_MIN,INT_MAX,max(left.size,right.size));
}

int largestBST(TreeNode<int>* root) 
{
    return largestBSTfunc(root).size;
}
