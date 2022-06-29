/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<map>
TreeNode<int>* buildTree(vector<int>& inorder,int instart,int inend,vector<int>& postorder,int poststart,int postend,map<int,int> &inmap)
{
    if(instart>inend || poststart>postend) return NULL;
    
    TreeNode<int> * root=new TreeNode<int>(postorder[postend]);
    int inroot=inmap[root->data];
    int numsleft=inroot-instart;
    root->left=buildTree(inorder,instart,inroot-1,postorder,poststart,poststart+numsleft-1,inmap);
    root->right=buildTree(inorder,inroot+1,inend,postorder,poststart+numsleft,postend-1,inmap);
        
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	map<int,int> inmap;
    int n = inOrder.size();
    if(n==0) return NULL;
    for(int i=0;i<n;i++)
    {
        inmap[inOrder[i]]=i;
    }
    
    return buildTree(inOrder,0,n-1,postOrder,0,n-1,inmap);
}
