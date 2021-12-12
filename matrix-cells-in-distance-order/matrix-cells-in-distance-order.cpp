class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int dist = abs(i-rCenter) + abs(j-cCenter);
                pq.push({dist, i, j});
            }
        }
        vector<vector<int>>umap;
        while(!pq.empty()){
            vector<int>x = pq.top();
            pq.pop();
            umap.push_back({x[1], x[2]});
        }
        return umap;
    }
};