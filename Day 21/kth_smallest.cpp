/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void small(TreeNode<int> *root, int &k,int &cnt)
{
    if(root==NULL) return;
    
    small(root->left,k,cnt);
    k--;
    if(k==0) 
    {
        cnt=root->data;
        return ;
    }
    small(root->right,k,cnt);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int cnt=0;
    small(root,k,cnt);
    return cnt;
}