// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    
void dfs(vector<vector<int>> adj,int v,vector<bool> &visited)
   {
       visited[v] = 1;
       for(int i=0;i<adj[v].size();i++)
       {
           if(adj[v][i]==1&&!visited[i])
               dfs(adj,i,visited);
       }
   }
 
 
   int numProvinces(vector<vector<int>> adj, int V) {
       int count = 0;
       vector<bool> visited(V,0);
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               count++;
               dfs(adj,i,visited);
           }
       }
       return count;
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends