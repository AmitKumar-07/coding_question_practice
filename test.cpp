// A Naive recursive solution for Rod cutting problem
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int countPalindromicSubsequences(string str) {
        //count distinct palindromic subsequences;
        int size=str.size();
        vector<int> prev(size);
        vector<int> next(size);
        unordered_map<char,int> map;
        vector<vector<int >> dp(size,vector<int>(size));
        int mod=1000000007;
        //previous
        for(int i=0;i<size;i++){
            if(map.find(str[i])!=map.end()){
                
                prev[i]=map[str[i]];
            }
            else{
                prev[i]=-1;
            }
            map[str[i]]=i; 
        }
        map.clear();
        //next
        for(int i=size-1;i>=0;i--){
            if(map.find(str[i]) != map.end()){
                next[i]=map[str[i]] ;
            }
            else{
                next[i]=-1;
            }
            map[str[i]]=i;
            
        }
        
        for(int gap=0;gap<size;gap++){
            for(int row=0,col=gap;col<size;row++,col++){
                if(gap==0){
                    dp[row][col]=1;
                }
                else if(gap==1){
                    dp[row][col]=2;
                }
                else{
                    if(str[row]!=str[col]){
                        dp[row][col]=(((dp[row][col-1]+dp[row+1][col])%mod) -dp[row+1][col-1]+mod)%mod;
                    }
                    else{
                        if(next[row]> prev[col]){
                            dp[row][col]=(((2*dp[row+1][col-1])%mod)+2)%mod; 
                        }
                        else if(next[row]==prev[col]){
                            dp[row][col]=(((2*dp[row+1][col-1])%mod)+1)%mod;
                        }
                        else if(next[row]!=prev[col]){
                            dp[row][col]=(((2*dp[row+1][col-1])%mod) - dp[next[row]+1][prev[col]-1]+mod)%mod;
                        }
                    }
                }
            }
        }
        
        return dp[0][size-1];
    }
};