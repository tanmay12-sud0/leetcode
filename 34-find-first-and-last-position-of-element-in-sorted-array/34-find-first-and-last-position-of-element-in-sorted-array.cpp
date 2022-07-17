class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>hash;
        int n = nums.size();
        if(binary_search(nums.begin(), nums.end(), target)){
            int it1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int it2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
            hash.push_back(it1);
            hash.push_back(it2);
            return hash;
        }else{
            return {-1, -1};
        }
    }
};