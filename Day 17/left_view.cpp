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

void f(TreeNode<int> *root,int level,vector<int> &ds)
{
    if(root==NULL) return ;
    
    if(ds.size()==level) ds.push_back(root->data);
    f(root->left,level+1,ds);
    f(root->right,level+1,ds);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ds;
    f(root,0,ds);
    return ds;
}