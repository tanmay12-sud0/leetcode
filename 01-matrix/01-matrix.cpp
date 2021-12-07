class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>>pq;
        // vector<vector<bool>>visited(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    pq.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!pq.empty()){
        int i = pq.front().first;
        int j = pq.front().second;
        pq.pop();

        for(int k=0; k<4; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx>=0 and xx<n and yy>=0 and yy<m and dist[xx][yy]==INT_MAX){
                dist[xx][yy] = dist[i][j]+1;
                pq.push({xx,yy});
            }
        }
        }
        
        return dist;
    }
};
