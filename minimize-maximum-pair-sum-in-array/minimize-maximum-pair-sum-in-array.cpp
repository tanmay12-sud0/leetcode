class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size()-1;
        int max_so_far = 0;
        while(start < end){
            max_so_far = max(max_so_far, nums[start]+nums[end]);
            start++,end--;
        }
        return max_so_far;
    }
};