/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool path(TreeNode<int> *root,vector<int> &ans,int x)
{
    if(root==NULL) return false;
    
    ans.push_back(root->data);
    if(root->data==x) return true;
    
    if(path(root->left,ans,x) || path(root->right,ans,x)) return true;
    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    path(root,ans,x);
    return ans;
}
