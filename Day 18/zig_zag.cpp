/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool LeftToRight=true;
    while(!q.empty())
    {
        int sz=q.size();
        int ans_size=ans.size();
        ans.resize(ans_size+sz);
        
        for(int i=0;i<sz;i++)
        {
            BinaryTreeNode<int> *node=q.front();
            q.pop();
            
            int index=(LeftToRight)?i:(sz-i-1);
            ans[ans_size+index]=node->data;
            
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
        LeftToRight=!LeftToRight;
    }
    return ans;
}
