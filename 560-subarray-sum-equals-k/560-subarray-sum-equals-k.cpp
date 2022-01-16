class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int pre = 0;
        unordered_map<int, int>hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            pre += nums[i];
            if(pre == k){
                count++;
            }
            if(hash.count(pre-k)){
                count += hash[pre-k];
            }
            hash[pre]++;
        }
        return count;
    }
};