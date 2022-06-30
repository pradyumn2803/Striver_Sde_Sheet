/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* buildTree(int start,int end,vector<int> &arr)
{
    if(start>end) return NULL;
    
    int mid=(start+end)/2;
    TreeNode<int>* root=new TreeNode<int>(arr[mid]);
    root->left=buildTree(start,mid-1,arr);
    root->right=buildTree(mid+1,end,arr);
    
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{    
    return buildTree(0,n-1,arr);
}