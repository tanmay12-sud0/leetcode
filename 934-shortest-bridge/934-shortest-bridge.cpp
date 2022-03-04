class Solution {
public:
    
    
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(vector<vector<bool>>&visited, vector<vector<int>>&dist, vector<vector<int>>&a, queue<pair<int, int>>&pq, int i, int j, int n, int m){
    visited[i][j] = true;
    dist[i][j] = 0;
    pq.push({i, j});
    for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]==1 and !visited[nx][ny]){
            // dist[nx][ny] = 0;
            dfs(visited, dist, a, pq, nx, ny, n, m);
        }
    }
}

    
    
    int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
        int m = grid[0].size();
    // vector<vector<int>>a(n, vector<int>(m, 0));
    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>>pq;
    vector<vector<bool>>visited(n, vector<bool>(m, false));
   

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin >> a[i][j];
//             dist[i][j] = INT_MAX;
//         }
//     }
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]){
                // cout << i << ", " << j << endl;
                flag = true;
                dfs(visited, dist, grid, pq, i, j, n, m);
                break;
            }
        }
       if(flag){
           break;
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

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         // cout << dist[i][j] << ", ";
    //         cout << a[i][j] << ", ";
    //     }
    //     cout << endl;
    // }
    int max_so_far = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // cout << dist[i][j] << ", ";
            if(!visited[i][j] and grid[i][j]==1){
                // cout << "hello";
                max_so_far = min(max_so_far, dist[i][j]);
            }
        }
        // cout << endl;
    }
    return max_so_far-1;
    }
};

