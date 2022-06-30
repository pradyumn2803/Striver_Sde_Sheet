/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<queue>
void connectNodes(BinaryTreeNode< int > *root) {
    if(root==NULL) return ;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {       
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            
            if(i==sz-1) node->next=NULL;
            else node->next=q.front();
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}