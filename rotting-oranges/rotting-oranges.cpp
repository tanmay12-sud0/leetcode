class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>a(n, vector<int>(m, 0));
        vector<vector<int>>dist(n, vector<int>(m, 0));
        queue<pair<int, int>>pq;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cin >> a[i][j];
                // dist[i][j] = INT_MIN;
                if(grid[i][j]==1){
                    dist[i][j] = 1;
                }
                if(grid[i][j]==2){
                    dist[i][j] = 0;
                    pq.push({i,j});
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
                if(xx>=0 and xx<n and yy>=0 and yy<m and dist[xx][yy]==1 and grid[xx][yy]==1){
                    dist[xx][yy] = dist[i][j]+10;
                    pq.push({xx,yy});
                }
            }
        }
        int max_so_far = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << dist[i][j] << ", ";
                if(dist[i][j]==1){
                    return -1;
                }
                max_so_far = max(max_so_far, dist[i][j]);
            }
                cout << endl;
        }   
       return max_so_far/10; 
        
    }
};

