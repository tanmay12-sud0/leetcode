class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(vector<vector<bool>>&visited, vector<vector<int>>&a, int i, int j, int n, int m){
    visited[i][j] = true;
    
    for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]==1 and !visited[nx][ny]){
            dfs(visited, a, nx, ny, n, m);
        }
    }
}
  
    
    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
    vector<vector<bool>>visited(n, vector<bool>(m, false));
 
    for(int i=0; i<n; i++){
        if(a[i][0]==1 and !visited[i][0]){
            dfs(visited, a, i, 0, n, m);
        }
    }

     for(int i=0; i<n; i++){
        if(a[i][m-1]==1 and !visited[i][m-1]){
            dfs(visited, a, i, m-1, n, m);
        }
    }
    for(int i=0; i<m; i++){
        if(a[0][i]==1 and !visited[0][i]){
            dfs(visited, a, 0, i, n, m);
        }
    }
    for(int i=0; i<m; i++){
        if(a[n-1][i]==1 and !visited[n-1][i]){
            dfs(visited, a, n-1, i, n, m);
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(!visited[i][j] and a[i][j]==1){
               count++;
           }
        }
        
    }
    return count;
    }
};