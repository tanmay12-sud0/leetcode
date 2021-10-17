class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        unordered_map<int, int>um;
        for(int i=0; i<nums.size(); i++){
            if(um.count(nums[i])){
                um[nums[i]]++;
            }else{
                um[nums[i]] = 1;
            }
        }
        for(auto x : um){
            pq.push(make_pair(x.second, x.first));
        }
        vector<int>umap;
        for(int i=0; i<k; i++){
            pair<int, int>pp = pq.top();
            umap.push_back(pp.second);
            pq.pop();
        }
        return umap;
    }
};