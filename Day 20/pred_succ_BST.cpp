/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans;
    int pred=-1,succ=-1;
    BinaryTreeNode<int>* cur=root;
    while(cur)
    {
        if(cur->data<key)
        {
            pred=cur->data;
            cur=cur->right;
        }
        else
        {
            cur=cur->left;
        }
    }
    
    while(root)
    {
        if(root->data<=key)
        {
            root=root->right;
        }
        else
        {
            succ=root->data;
            root=root->left;
        }
    }
    ans.first=pred;
    ans.second=succ;
    return ans;
}
