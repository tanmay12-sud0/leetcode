class Solution {
public:
    
    int dx[8] = {1,-1,0,0,1,-1,-1,1};
    int dy[8] = {0,0,1,-1,1,1,-1,-1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1){
            return -1;
        }
        if(n==1 and m==1 and grid[0][0]==0){
            return 1;
        }
    vector<vector<int>>dist(n, vector<int>(m, 0));
    queue<pair<int, int>>pq;
    vector<vector<bool>>visited(n, vector<bool>(m, false));
  
 
    dist[0][0] = 0;
    pq.push(make_pair(0,0));
    

    while(!pq.empty()){
        int i = pq.front().first;
        int j = pq.front().second;
        pq.pop();

        for(int k=0; k<8; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx>=0 and xx<n and yy>=0 and yy<m and dist[xx][yy]==0 and grid[xx][yy]==0){
                dist[xx][yy] = dist[i][j]+1;
                pq.push({xx,yy});
            }
        }
    }
        if(dist[n-1][m-1]!=0){
            return dist[n-1][m-1]+1;
        }
        return -1;
    }
};