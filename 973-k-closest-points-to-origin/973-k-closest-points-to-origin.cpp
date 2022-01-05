class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int n = points.size();
        
        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist, x, y});
        }
        
        vector<vector<int>>umap;
        for(int i=0; i<k; i++){
            vector<int>p = pq.top();
            pq.pop();
            umap.push_back({p[1], p[2]});
        }
        return umap;
    }
};