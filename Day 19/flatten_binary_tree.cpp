/************************************************************

    Following is the TreeNode class structure.

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
#include<stack>
// Approach-1
// TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
// {   
//     stack<TreeNode<int> *>st;
//     st.push(root);
//     while(!st.empty())
//     {
//         TreeNode<int> *cur=st.top();
//         st.pop();
        
//         if(cur->right) st.push(cur->right);
//         if(cur->left) st.push(cur->left);
        
//         if(!st.empty())
//         {
//             cur->right=st.top();
//         }
//         cur->left=NULL;
//     }
//     return root;
// }

//Approach-2
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *cur=root;
    
    while(cur!=NULL)
    {
        if(cur->left!=NULL) 
        {
            TreeNode<int> *prev=cur->left;
            while(prev->right!=NULL) prev=prev->right;
            
            prev->right=cur->right;
            cur->right=cur->left;
        }
        cur=cur->right;
    }
    return root;
}