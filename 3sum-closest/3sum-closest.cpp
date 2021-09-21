class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_sum = INT_MAX;
        int sumclass = 0;
        for(int i=0; i<n-2; i++){
            int start = i+1;
            int end = n-1;
            while(start < end){
                int sum=nums[i]+nums[start]+nums[end];
                int diff = abs(sum-target);
                if(diff < min_sum){
                    min_sum = diff;
                    sumclass = sum;
                }
                if(sum > target){
                    end--;
                }else{
                    start++;
                }
            }
        }
        return sumclass;
    }
};