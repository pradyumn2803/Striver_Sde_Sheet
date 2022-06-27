/************************************************************

    Following is the Binary Tree node structure:
    
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
bool leaf(TreeNode<int>* root)
{
    return (root->left==NULL && root->right==NULL);
}

void LeftTraversal(TreeNode<int>* root,vector<int> &res)
{
    TreeNode<int>* cur=root->left;
    while(cur)
    {
        if(!(leaf(cur))) res.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}

void RightTraversal(TreeNode<int>* root,vector<int> &res)
{
    TreeNode<int>* cur=root->right;
    int i=0;
    while(cur)
    {
        if(!(leaf(cur))) 
        {
            res.insert(res.end()-i,cur->data);
            i++;
        }
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
}

void LeafTraversal(TreeNode<int>* root,vector<int> &res)
{
    if(leaf(root)) 
    {
        res.push_back(root->data);
        return ;
    }
    
    if(root->left) LeafTraversal(root->left,res);
    if(root->right) LeafTraversal(root->right,res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(root==NULL) return res;
    
    if(!leaf(root)) res.push_back(root->data);
    LeftTraversal(root,res);
    LeafTraversal(root,res);
    RightTraversal(root,res);
    return res;
}