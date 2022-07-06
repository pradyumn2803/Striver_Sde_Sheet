/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

void dfs(graphNode *node,graphNode *copy,vector<graphNode*> &vis)
{
    vis[copy->data]=copy;
    
    for(auto it:node->neighbours)
    {
        if(vis[it->data]==NULL)
        {
            graphNode* newnode=new graphNode(it->data);
            (copy->neighbours).push_back(newnode);
            dfs(it,newnode,vis);
        }
        else
        {
            (copy->neighbours).push_back(vis[it->data]);
        }
    }
}

graphNode *cloneGraph(graphNode *node)
{
    int n = (int) 1e5;
    graphNode* copy=new graphNode(node->data);
    vector<graphNode*> vis(n+1,NULL);
    dfs(node,copy,vis);
    return copy;
}