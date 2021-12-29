class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>hash;
        int n = points.size();
        priority_queue<vector<int>>pq;
        for(int i=0; i<n; i++){
            int x = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            pq.push({x, points[i][0], points[i][1]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            vector<int>umap = pq.top();
            pq.pop();
            hash.push_back({umap[1], umap[2]});
        }
        return hash;
    }
};