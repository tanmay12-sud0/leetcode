class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int>hash;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(hash.count(nums[i]+k)){
                count += (hash[nums[i]+k]);
            }
            if(hash.count(nums[i]-k)){
                count += (hash[nums[i]-k]);
            }
            hash[nums[i]]++;
        }
        return count;
    }
};