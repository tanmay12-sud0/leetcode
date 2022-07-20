class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
       vector<int>umap;
        unordered_map<int, int>hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(hash.count(target- nums[i])){
                return {i, hash[target-nums[i]]};
            }
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};