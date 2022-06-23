/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> pre;
    if(root==NULL) return pre;

    stack<TreeNode*> st;
    TreeNode* node=root;
    st.push(node);
    
    while(!st.empty())
    {
        node=st.top();
        st.pop();
        pre.push_back(node->data);
        
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);
    }
    return pre;
}