/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<set>
#include<queue>
#include<map>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    map<int,map<int,vector<int>>> nodes;
    queue<pair<TreeNode<int> *,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto p=q.front();
        TreeNode<int> *node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        q.pop();
        
        nodes[x][y].push_back(node->data);
        
        if(node->left!=NULL)
            q.push({node->left,{x-1,y+1}});
        if(node->right!=NULL)
            q.push({node->right,{x+1,y+1}});       
    }
    
    for(auto p:nodes)
    {
        for(auto q:p.second)
        {
            ans.insert(ans.end(),q.second.begin(),q.second.end());
        }
    }
    
    return ans; 
}