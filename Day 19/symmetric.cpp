/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool symmetric(BinaryTreeNode<int>*p,BinaryTreeNode<int>*q)
{
    if(p==NULL || q==NULL) return (p==q);
    
    return (p->data==q->data && symmetric(p->left,q->right) && symmetric(p->right,q->left));
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL) return true;
    return symmetric(root->left,root->right);
}