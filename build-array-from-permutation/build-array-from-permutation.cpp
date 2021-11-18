class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>hash(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            hash[i] = nums[nums[i]];
        }
        return hash;
    }
};