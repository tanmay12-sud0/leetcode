class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum =0;
        vector<int> run(nums.size());
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            run[i] = sum;
        }
        return run;
    }
};