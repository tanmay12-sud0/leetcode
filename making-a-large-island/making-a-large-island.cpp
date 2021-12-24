class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int landcnt=2;
        int n=grid.size();
        unordered_map<int,int> area;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=landcnt;
                    area[landcnt]=dfs(grid,i,j,landcnt);
                    landcnt++;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int tmparea=1;
                    set<int> landtype;
                    if(i-1>=0 && grid[i-1][j]>0){
                        landtype.insert(grid[i-1][j]);
                    }
                    if(j-1>=0 && grid[i][j-1]>0){
                        landtype.insert(grid[i][j-1]);
                    }
                    if(i+1<n && grid[i+1][j]>0){
                        landtype.insert(grid[i+1][j]);
                    }
                    if(j+1<n && grid[i][j+1]>0){
                        landtype.insert(grid[i][j+1]);
                    }
                    for(auto& lt:landtype){
                        tmparea+=area[lt];
                    }
                    res=max(res,tmparea);
                }
            }
        }
    
        return res==0?n*n:min(res,n*n);
    }
    int dfs(vector<vector<int>>& grid, int row, int col, int landtype){
        int cnt=1;
        if(row-1>=0 && grid[row-1][col]==1 ){
            grid[row-1][col]=landtype;
            cnt+=dfs(grid,row-1,col,landtype);
        }
        if(col-1>=0 && grid[row][col-1]==1 ){
            grid[row][col-1]=landtype;
            cnt+=dfs(grid,row,col-1,landtype);
        }
        if(row+1<grid.size() && grid[row+1][col]==1){
            grid[row+1][col]=landtype;
            cnt+=dfs(grid,row+1,col,landtype);
        }
        if(col+1<grid.size() && grid[row][col+1]==1 ){
            grid[row][col+1]=landtype;
            cnt+=dfs(grid,row,col+1,landtype);
        }
        return cnt;
    }
};


























// class Solution {
// public:
    
//     int dx[4] = {1,-1,0,0};
//     int dy[4] = {0,0,1,-1};
// void dfs(vector<vector<bool>>&visited,vector<vector<int>>&grid , int i, int j, int n, int m, int color){
//     visited[i][j] = true;
//     grid[i][j] = color;
//     for(int k=0; k<4; k++){
//         int nx = i+dx[k];
//         int ny = j+dy[k];
//         if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1 and !visited[nx][ny]){
//             dfs(visited, grid, nx, ny, n, m, color);
//         }
//     }
// }


//     int largestIsland(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>>visited(n, vector<bool>(m, false));
//         int color = 10;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(!visited[i][j] and grid[i][j]==1){
//                     dfs(visited, grid, i, j, n, m, color);
//                     color++;
//                 }
//             }
//         }
//         unordered_map<int, int>hash;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]!=0){
//                     hash[grid[i][j]]++;
//                 }
//             }
//             cout << endl;
//         }
//         int max_so_far = INT_MIN;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 unordered_set<int>s;
//                 if(grid[i][j]==0){
//                     if(i-1>=0 and grid[i-1][j]!=0){
//                         s.insert(grid[i-1][j]);
//                     }
//                     if(i+1<n and grid[i+1][j]!=0){
//                         s.insert(grid[i+1][j]);
//                     }
//                     if(j-1>=0 and grid[i][j-1]!=0){
//                         s.insert(grid[i][j-1]);
//                     }
//                     if(j+1<m and grid[i][j+1]!=0){
//                         s.insert(grid[i][j+1]);
//                     }
//                 }
//                 int sum = 0;
//                 for(auto x : s){
//                     sum += hash[x];
//                 }
//                 max_so_far = max(max_so_far, sum+1);
//                 for(auto x : hash){
//                     cout << x.second << endl;
//                      max_so_far = max(max_so_far, x.second);
//                 }
//             }
//         }
//         return max_so_far;
//     }
// };