class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
void dfs(vector<vector<bool>>&visited,vector<vector<int>>& grid2,vector<vector<int>>& grid1, int i, int j, int n, int m, bool &flag){
    visited[i][j] = true;
    
    if(grid1[i][j] != grid2[i][j]){
        flag =  false;
    }
    
    for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        
        if(nx>=0 and nx<n and ny>=0 and ny<m and grid2[nx][ny]==1 and !visited[nx][ny]){
            dfs(visited, grid2,grid1, nx, ny, n, m, flag);
           
        }
    }
    
    return;
    
}
    
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int count = 0;
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool flag = true;
                if(grid2[i][j]==1 and !visited[i][j]){
                    dfs(visited, grid2, grid1, i, j, n ,m, flag);
                    if(flag){
                        count++;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << visited[i][j] << ", ";
            }
            cout << endl;
        }
        return count;
        
    }
};