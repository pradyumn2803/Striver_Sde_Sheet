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
#include<map>
TreeNode<int> *buildtree(vector<int> &inorder,int instart,int inend,vector<int> &preorder,int prestart,int preend,map<int,int> &inmap)
{
    if(instart>inend || prestart>preend) return NULL;
    
    TreeNode<int> *root=new TreeNode<int>(preorder[prestart]);
    int inroot=inmap[root->data];
    int numleft=inroot-instart;
    
    root->left=buildtree(inorder,instart,inroot-1,preorder,prestart+1,prestart+numleft,inmap);
    root->right=buildtree(inorder,inroot+1,inend,preorder,prestart+numleft+1,preend,inmap);
    
    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map<int,int> inmap;
    if(inorder.size()==0) return NULL;
    for(int i=0;i<inorder.size();i++) inmap[inorder[i]]=i;
    
    TreeNode<int> *root=buildtree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inmap);
    return root;
}

