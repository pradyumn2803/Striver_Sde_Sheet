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
#include<stack>
class BSTiterator
{
public:
    stack<TreeNode<int> *> st;
    
    void pushAll(TreeNode<int> *root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *ele=st.top();
        st.pop();
        TreeNode<int> *cur=ele;
        if(cur->right)
        {
            cur=cur->right;
            pushAll(cur);
        }
        return ele->data;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/