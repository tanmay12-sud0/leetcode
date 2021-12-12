class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(vector<vector<bool>>&visited, vector<vector<char>>&a, int i, int j, int n, int m){
    visited[i][j] = true;
    for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]=='X' and !visited[nx][ny]){
            dfs(visited, a, nx, ny, n, m);
        }
    }
}
    
    int countBattleships(vector<vector<char>>& board) {
        int n =board.size();
        int m = board[0].size();
        int count = 0;
        vector<vector<bool>>visited(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] and board[i][j] == 'X'){
                    dfs(visited, board, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};