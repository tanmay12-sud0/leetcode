// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  vector<int>dx{0,0,1,1,-1,-1,1,-1},dy{-1,1,-1,1,-1,1,0,0};
   void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited,int n,int m)
   {
       visited[i][j]=1;
       for(int k=0;k<8;k++)
       {
           int x=i+dx[k];
           int y=j+dy[k];
           if(x>=0 && y>=0 && x<n && y<m)
           {
               if(grid[x][y]=='1' && visited[x][y]==0)
               {
                   dfs(x,y,grid,visited,n,m);
               }
           }
       }
   }
   
   int numIslands(vector<vector<char>>& grid)
   {
       int n=grid.size(),m=grid[0].size(),ans=0;
       vector<vector<int>>visited(n,vector<int>(m,0));
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]=='1' && visited[i][j]==0)
               {
                   ans++;
                   dfs(i,j,grid,visited,n,m);
               }
           }
       }
       return ans;
   }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends