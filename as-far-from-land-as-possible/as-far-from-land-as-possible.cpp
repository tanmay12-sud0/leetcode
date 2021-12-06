class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    
    int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
    queue<vector<int>>pq;
    vector<vector<bool>>visited(n, vector<bool>(m, false));
   
    int count1 = 0;
        int count2 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==0){
                 count1++;
            }
            if(grid[i][j]==1){
                count2++;
            }
            if(grid[i][j]){
                dist[i][j] = 0;
               
                pq.push({i,j, i, j});
            }
        }
    }
   if(count1 == n*m or count2==n*m){
       return -1;
   }

    while(!pq.empty()){
        int i = pq.front()[0];
        int j = pq.front()[1];
        int prox = pq.front()[2];
        int proy = pq.front()[3];
        pq.pop();

        for(int k=0; k<4; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx>=0 and xx<n and yy>=0 and yy<m and dist[xx][yy]==INT_MAX){
                dist[xx][yy] = abs(yy-proy)+abs(xx-prox);
                pq.push({xx,yy, prox, proy});
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dist[i][j] << ", ";
            // cout << a[i][j] << ", ";
        }
        cout << endl;
    }
    int max_so_far = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
                max_so_far = max(max_so_far, dist[i][j]);
        }
    }
    return max_so_far;
    }
};


