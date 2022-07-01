/************************************************************
    Following is the Binary Search Tree node structure
    
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
void large(TreeNode<int> *root,int &k,int &cnt)
{
    if(root==NULL) return ;
    
    large(root->right,k,cnt);
    k--;
    if(k==0) 
    {
        cnt=root->data;
        return ;
    }
    
    large(root->left,k,cnt);
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int cnt=-1;
    large(root,k,cnt);
    return cnt;
}
