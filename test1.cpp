#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	//dfs
// 	bool solve(int node,vector<bool> &vist,vector<bool> &rec,vector<int> adj[])
// 	{
	   
// 	      vist[node]=true;
//           rec[node]=true;
           
// 	    for(int child:adj[node])
// 	    {
// 	        if(vist[child]==0)
// 	        {
// 	            if(solve(child,vist,rec,adj))
// 	               return true;
// 	        }
// 	        else
// 	        {
// 	            if(rec[child]==true)
// 	                return true;
// 	        }
// 	    }
// 	    rec[node]=false;
// 	    return false;
// 	}

//bfs
	bool isCyclic(int V, vector<int> adj[])
	{
	   //dfs
	   //	vector<bool> vist(V,false);
	   //	for(int i=0;i<V;i++)
	   //	{ 
	   //	    if(vist[i]==0)
	   //	    {
	   //	        vector<bool> rec(V,false);
	   //	        if(solve(i,vist,rec,adj))
	   //	             return true;
	   //	    }
	   	    
	   //	}
	   //	return false;
	   
	   ///bfs
	   vector<int> in(V,0);
	    int cnt=0;
	   for(int i=0;i<V;i++)
	   {
	       for(int child:adj[i])
	       {
	           in[child]++;
	       }
	   }
	       
	  
	  queue<int> q;
	   for(int i=0;i<V;i++)
	   {
	       if(in[i]==0)
	       q.push(i);
	   }
	   
	   while(q.size()>0)
	   {
	       int node=q.front();
	       q.pop();
	       
	       for(int child:adj[node])
	       {
	            in[child]--;
	            if(in[child]==0)
	             {q.push(child);cnt++;}
	             
	       }
	   }
	  for(int i=0;i<V;i++)
	  {
	      if(in[i]>0)
	      return true;
	  }
         
        
	   return false;
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends