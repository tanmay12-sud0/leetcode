class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(pq.size()<k){
                pq.push({nums[i], i});
            }
            else if(pq.size()==k and nums[i]>pq.top().first){
                pq.pop();
                pq.push({nums[i], i});
            }
        }
        vector<vector<int>>umap;
        while(!pq.empty()){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            umap.push_back({idx, val});
        }
        sort(umap.begin(), umap.end());
        vector<int>hash2;
        for(auto x : umap){
            hash2.push_back(x[1]);
        }
        return hash2;
    }
};