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

int height(TreeNode<int> *root,int &dia)
{
    if(root==NULL) return 0;
    
    int lh=height(root->left,dia);
    int rh=height(root->right,dia);
    dia=max(dia,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter=0;
    height(root,diameter);
    return diameter;
}
