class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int>hash;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(hash.count(nums[i])){
                res += hash[nums[i]];
            }
            hash[nums[i]]++;
        }
        return res;
    }
};