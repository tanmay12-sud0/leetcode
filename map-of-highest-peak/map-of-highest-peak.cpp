class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& maze) {
         queue<pair<int, int>>pq;
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(maze[i][j] == 1){
                    dist[i][j] = 0;
                    pq.push(make_pair(i, j));
                }
            }
        }
        
        // pq.push(make_pair(entrance[0], entrance[1]));
        // dist[entrance[0]][entrance[1]] = INT_MAX;
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
        
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dist[i][j] << ", ";
        }
        cout << endl;
    }
    return dist;                            
    }
};



// class Solution {
// public:
    
//     int dx[4] = {1,-1,0,0};
//     int dy[4] = {0,0,1,-1};
    
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//         queue<pair<int, int>>pq;
//         int n = maze.size();
//         int m = maze[0].size();
//         vector<vector<int>>dist(n, vector<int>(m, 0));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(maze[i][j] == '+'){
//                     dist[i][j] = INT_MAX;
//                 }
//             }
//         }
        
//         pq.push(make_pair(entrance[0], entrance[1]));
//         // dist[entrance[0]][entrance[1]] = INT_MAX;
//         while(!pq.empty()){
//         int i = pq.front().first;
//         int j = pq.front().second;
//         pq.pop();

//         for(int k=0; k<4; k++){
//             int xx = i + dx[k];
//             int yy = j + dy[k];
//             if(xx>=0 and xx<n and yy>=0 and yy<m and dist[xx][yy]!=INT_MAX){
//                 dist[xx][yy] = dist[i][j]+1;
//                 pq.push({xx,yy});
//                 if(xx == 0 || yy ==0 || xx==n-1 || yy==m-1)
//                         return dist[xx][yy];
//                 }
//             }
//         }
        
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cout << dist[i][j] << ", ";
//         }
//         cout << endl;
//     }    
        
//       return -1;  
        
//     }
// };