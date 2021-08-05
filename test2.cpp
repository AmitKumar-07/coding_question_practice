#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	int vist[5061];
	stack<int> s;
	void dfs(vector<int> adj[],int V,int node)
	{
	    vist[node]=1;
	    for(int child : adj[node])
	    {
	        if(vist[child]==0)
	         dfs(adj,V,child);
	    }
	    s.push(node);
	    return;
	}
	 void dfsScc(vector<int> revAdj[],int V,int node)
	 {
	       vist[node]=1;
	    for(int child : revAdj[node])
	    {
	        if(vist[child]==0)
	         dfs(revAdj,V,child);
	    }
	    return;
	 }
    int kosaraju(int V, vector<int> adj[])
     {//  return 4; 
        memset(vist,0,sizeof(vist));
        vector<int> revAdj[V];
        for(int i=0;i<V;i++)
        {
            for(int child : adj[i])
            {
                revAdj[child].push_back(i);
            }
        }
        // return 4;
        for(int i=0;i<V;i++)
        {
            if(vist[i]==0)
            {
                dfs(adj,V,i);
            }
        }
        // return 4;
        memset(vist,0,sizeof(vist));
        int res=0;
        while(!s.empty())
        {
            int curr=s.top();
                     s.pop();
              if(vist[curr]==0)
              {
                  dfsScc(revAdj,V,curr);
                  res++;
              }
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends