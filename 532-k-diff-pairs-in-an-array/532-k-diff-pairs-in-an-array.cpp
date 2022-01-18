class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int>umap;
        set<pair<int, int>>ss;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(umap.count((k+nums[i]))){
                ss.insert(make_pair(min((k+nums[i]), nums[i]), max((k+nums[i]), nums[i])));
            }
            if(umap.count(nums[i]-k)){
                ss.insert(make_pair(min(nums[i]-k, nums[i]), max(nums[i]-k, nums[i])));
            }
            umap[nums[i]]++;
        }
        
        for(auto x : ss){
            cout << x.first << ", " << x.second << endl;
        }
        return ss.size();
    }
};