//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&graph)
	{
	    int V=graph.size();
    int dist[V][V], i, j, k,cnt=INT_MAX/2;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
           { 
                 if(graph[i][j]==-1)
                  dist[i][j]=cnt;
                  else
                  dist[i][j] = graph[i][j];
           }
    }
    for (k = 0; k < V; k++) 
    {
        for (i = 0; i < V; i++) 
        {
            for (j = 0; j < V; j++) 
            {
                if(graph[i][k]!=cnt&&graph[k][j]!=cnt)
                {
                    if (dist[i][j] > (dist[i][k] + dist[k][j]))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
         { 
             if(dist[i][j]==cnt)
             graph[i][j]=-1;
             else
              graph[i][j] = dist[i][j];
         }
    }
          return;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends