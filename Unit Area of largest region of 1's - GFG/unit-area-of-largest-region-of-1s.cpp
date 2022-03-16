// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:

    // void solve(vector<vector<int>> grid, vector<vector<bool>>& visited, int i, int j, int n, int m, int &cnt){
    //     visited[i][j] = true;
        
    //     static int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    //     static int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
        
    //     for(int p=0; p<8; p++){
    //         int xx = i + dx[p];
    //         int yy = j + dy[p];
    //         if(xx<n and xx>=0 and yy<m and yy>=0 and grid[xx][yy]==1 and !visited[xx][yy]){
    //             cnt += 1;
    //             solve(grid, visited, xx, yy, n, m, cnt);
    //         }
    //     }
    //     return;
    // }
    
    
    
    // int findMaxArea(vector<vector<int>>& grid) {
    //     int row = grid.size();
    //     int col = grid[0].size();
    //     vector<vector<bool>>visited(row, vector<bool>(col, false));
    //     int max_so_far = INT_MIN;
    //     for(int i=0; i<row; i++){
    //         for(int j=0; j<col; j++){
    //             if(!visited[i][j] and grid[i][j]==1){
    //                 int cnt = 0;
    //                 solve(grid, visited ,i, j, row, col, cnt);
    //                 max_so_far = max(max_so_far, cnt);
    //             }
    //         }
    //     }
    //     return max_so_far;
    
    
void DFS(int r, int c,vector<vector<bool>>& visited, int &ar, vector<vector<int>>& grid){
       visited[r][c]=true;
       ar=ar+1;
       int row=grid.size();
       int col=grid[0].size();
       
       static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
       static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
       for(int i=0; i<8; i++){
           int a=r+rowNbr[i];
           int b=c+colNbr[i];
           
           if(a>=0 && a<row && b>=0 && b<col && !visited[a][b] && grid[a][b]){
               DFS(a, b, visited, ar, grid);
           }
       }    
       
   }
   int findMaxArea(vector<vector<int>>& grid) {
       // Code here
       int row=grid.size();
       int col=grid[0].size();
       
       int max_ar=INT_MIN; //store maximum area
       int ar=0; //store area
       // vector<vector<bool>>visited;
       vector<vector<bool>> visited(row, vector<bool>(col, false));
       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               if(!visited[i][j] && grid[i][j]){
                   DFS(i,j,visited,ar, grid);
                   max_ar=max(max_ar, ar);
               }
               ar=0;
           }
       }
       return max_ar;
   
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends