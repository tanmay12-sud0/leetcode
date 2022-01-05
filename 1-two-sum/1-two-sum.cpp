class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hash;
        vector<int>umap;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(hash.count(target-nums[i])){
                umap.push_back(hash[target-nums[i]]);
                umap.push_back(i);
                return umap;
            }else{
                hash[nums[i]] = i;
            }
        }
        return umap;
    }
};