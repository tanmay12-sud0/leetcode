class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int value = 0;
        for(int i=0; i<nums.size(); i++){
            value ^= nums[i];
        }
        for(int i=0; i<=n; i++){
            value ^= i;
        }
        return value;
    }
};