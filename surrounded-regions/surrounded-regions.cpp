class Solution {
public:
    
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
void dfs(vector<vector<bool>>&visited, vector<vector<char>>&a, int i, int j, int n, int m){
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]=='O' and !visited[nx][ny]){
            dfs(visited, a, nx, ny, n, m);
        }
    }
    }
    
    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(visited, board, i, 0, n, m);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][m-1] == 'O'){
                dfs(visited, board, i, m-1, n, m);
            }
        }
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O'){
                dfs(visited, board, 0, i, n, m);
            }
        }
        for(int i=0; i<m; i++){
            if(board[n-1][i] == 'O'){
                dfs(visited, board, n-1, i, n, m);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] and board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
        
    }
};