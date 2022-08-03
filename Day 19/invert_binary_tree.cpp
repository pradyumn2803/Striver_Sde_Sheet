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
bool isleaf(TreeNode<int> *root)
{
    return ((root->left==NULL) && (root->right==NULL));
}

bool helper(TreeNode<int> *root,TreeNode<int> *leaf,stack<TreeNode<int>*>&st)
{
    st.push(root);
    if(isleaf(root))
    {
        if(root->data == leaf->data) return true;
        else{
            st.pop();
            return false;
        }
    }
    bool left=false ,right=false;
    if(root->left!=NULL) left=helper(root->left,leaf,st);
    if(left) return true;
    if(root->right!=NULL) right=helper(root->right,leaf,st);
    if(right) return true;
    st.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    if(!root) return root;
    stack<TreeNode<int>*> st;
    helper(root,leaf,st);
    TreeNode<int> *newRoot=st.top();
    st.pop();
    TreeNode<int> *parent=newRoot;
    
    while(!st.empty())
    {
        TreeNode<int> *curnode = st.top();
        st.pop();
        if(curnode->left==parent)
        {
            curnode->left=NULL;
            parent->left=curnode;
        }
        else{
            curnode->right=curnode->left;
            curnode->left=NULL;
            parent->left=curnode;
        }
        parent=parent->left;
    }
    return newRoot;
}
