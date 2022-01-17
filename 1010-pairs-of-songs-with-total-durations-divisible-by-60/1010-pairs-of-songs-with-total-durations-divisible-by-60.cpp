class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i]%60;
        }
        int cnt = 0;
        unordered_map<int, int>hash;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cnt += hash[nums[i]];
            }
            if(hash.count(60-nums[i])){
                cnt += hash[60-nums[i]];
            }
            hash[nums[i]]++;
        }
        return cnt;
    }
};