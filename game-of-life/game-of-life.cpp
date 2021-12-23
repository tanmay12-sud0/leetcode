class Solution {
public:
    
    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>umap(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1){
                    int count = 0;
                    for(int k=0; k<8; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0 and nx<n and ny>=0 and ny<m and board[nx][ny]==1){
                            count++;
                        }
                    }
                    cout << i <<", " << j << " = " << count << "upper" << endl;
                    if(count < 2){
                        umap[i][j] = 0;
                    }
                    if(count == 2 or count==3){
                        umap[i][j] = 1;
                    }
                    if(count>3){
                        umap[i][j] = 0;
                    }
                }else{
                    
                    int count = 0;
                    for(int k=0; k<8; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0 and nx<n and ny>=0 and ny<m and board[nx][ny]==1){
                            count++;
                        }
                    }
                    cout << i <<", " << j << " = " << count << endl;
                    if(count ==3){
                        umap[i][j] = 1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = umap[i][j];
                cout << umap[i][j] << ", ";
            }
            cout << endl;
        }
        return;
    }
};