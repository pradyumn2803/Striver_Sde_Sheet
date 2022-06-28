/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<algorithm>
long long int maxPath(TreeNode<int> *root,long long int &maxi,long long int &cnt)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) cnt++;
    long long int left=maxPath(root->left,maxi,cnt);
    long long int right=maxPath(root->right,maxi,cnt);
    maxi=max(maxi,root->val+left+right);
    return root->val+max(left,right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL) return -1;
    long long int maxi=-1e9,cnt=0;
    maxPath(root,maxi,cnt);
    if(cnt==1) return -1;
    return maxi;
}