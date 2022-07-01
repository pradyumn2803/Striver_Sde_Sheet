/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<stack>
class BSTiter
{
private:
    
    stack<BinaryTreeNode<int> *> st;
    bool reverse;
public:
    void pushAll(BinaryTreeNode<int> *root)
    {
        while(root)
        {
            st.push(root);
            if(reverse) root=root->right;
            else root=root->left;
        }
    }
    
    BSTiter(BinaryTreeNode<int> *root,bool isreverse)
    {
        reverse=isreverse;
        pushAll(root);
    }
    
    bool hasnext()
    {
        return !st.empty();
    }
    
    int next()
    {
        BinaryTreeNode<int> *res=st.top();
        st.pop();
        
        if(!reverse) pushAll(res->right);
        else pushAll(res->left);
        
        return res->data;        
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTiter l(root,false);
    BSTiter r(root,true);
    
    int i=l.next();
    int j=r.next();
    
    while(i<j)
    {
        if(i+j==k) return true;
        else if((i+j)<k) i=l.next();
        else j=r.next();
    }
    
    return false;
}