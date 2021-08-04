#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> res;
    void solve(vector<vector<int>> &m,int n,int i,int j,string str,vector<vector<int>> &vist)
    {
         
            if(i==n-1&&j==n-1)
            {
                res.push_back(str);
                  return;
            }
            vist[i][j]=1;
           int x=i+1,y=j;
           if(x>=0&&x<n&&y>=0&&y<n)
           {
               if(m[x][y]==1&&vist[x][y]==0)
               {
                   str.push_back('D');
                   solve(m,n,x,y,str,vist);
                   str.pop_back();
               }
           }
           x=i,y=j+1;
            if(x>=0&&x<n&&y>=0&&y<n)
           {
               if(m[x][y]==1&&vist[x][y]==0)
               {
                   str.push_back('R');
                   solve(m,n,x,y,str,vist);
                   str.pop_back();
               }
           }
            x=i,y=j-1;
            if(x>=0&&x<n&&y>=0&&y<n)
           {
               if(m[x][y]==1&&vist[x][y]==0)
               {
                   str.push_back('L');
                   solve(m,n,x,y,str,vist);
                   str.pop_back();
               }
           }
            x=i-1,y=j;
            if(x>=0&&x<n&&y>=0&&y<n)
           {
               if(m[x][y]==1&&vist[x][y]==0)
               {
                   str.push_back('U');
                   solve(m,n,x,y,str,vist);
                   str.pop_back();
               }
           }
           vist[i][j]=0;
    }    
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        res.clear();
        if(m[0][0]==0)
         return res;
        vector<vector<int>> vist(n+1,vector<int> (n+1,0));
        solve(m,n,0,0,"",vist);
        sort(res.begin(),res.end());
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
