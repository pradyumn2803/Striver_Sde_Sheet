#include<queue>
#include<map>
struct Node
{
    int left,right,height;  
    Node(int l,int r,int h)
    {
        left=l;
        right=r;
        height=h;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int n){
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[inorder[i]]=i;
    
    Node *init=new Node(0,n-1,0);
    queue<Node*> q;
    q.push(init);
    int maxHeight=0;
    for(int i=0;i<n;i++)
    {
        Node *node=q.front();
        q.pop();
        
        int curpos=mp[levelorder[i]];
        
        if(curpos>node->left)
        {
            Node *newnode = new Node(node->left,curpos-1,node->height+1); 
            maxHeight=max(maxHeight,newnode->height);           
            q.push(newnode);
        }
        
        if(curpos<node->right)
        {
            Node *newnode = new Node(curpos+1,node->right,node->height+1); 
            maxHeight=max(maxHeight,newnode->height);
            q.push(newnode);
        }
    }
    return maxHeight;
}