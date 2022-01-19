class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>hash;
        int cnt = 0;
        int pre = 0;
        // hash[0]++;
        for(int i=0; i<nums.size(); i++){
            pre += nums[i];
            if(pre == goal){
                cnt++;
            }
            if(hash.count(pre-goal)){
                cnt += hash[pre-goal];
            }
            hash[pre]++;
        }
        return cnt;
    }
};