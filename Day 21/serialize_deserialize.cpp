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
#include<queue>
#include<string>
#include<sstream>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(root==NULL) return "";
    
    string s="";
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode<int> *cur=q.front();
        q.pop();
        
        if(cur==NULL) s.append("#,");
        else s.append(to_string(cur->data)+',');
        if(cur)
        {
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size()==0) return NULL;
    
    stringstream s(serialized);
    string str;
    getline(s,str,',');
    TreeNode<int>* root=new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode<int>* node=q.front();
        q.pop();
        
        getline(s,str,',');
        if(str=="#") node->left=NULL;
        else 
        {
            TreeNode<int>* leftnode=new TreeNode<int>(stoi(str));
            node->left=leftnode;
            q.push(leftnode);
        }
        
        getline(s,str,',');
        if(str=="#") node->right=NULL;
        else 
        {
            TreeNode<int>* rightnode=new TreeNode<int>(stoi(str));
            node->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}



