/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<map>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL) return ans;
    
    queue<pair<TreeNode<int> *,int>> q;
    map<int,int> mp;
    q.push({root,0});
    
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        
        TreeNode<int> *node=p.first;
        int line=p.second;
        if(mp.find(line)==mp.end()) mp[line]=node->val;
        
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1});
    }
    
    for(auto it:mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}