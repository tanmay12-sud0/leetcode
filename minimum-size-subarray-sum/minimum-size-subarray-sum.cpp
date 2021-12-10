class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        int j = 0;
        bool flag = true;
        int min_so_far = INT_MAX;
        for(int i=0; i<n; i++){
            pre += nums[i];
            while(pre >= target){
                flag = false;
                min_so_far = min(min_so_far, i-j+1);
               // while(pre > target){
                    // j++;
                    pre -= nums[j++];
                // }
               // min_so_far = min(min_so_far, i-j+1);
            }
             
        }
        if(flag){
            return 0;
        }
        return min_so_far;
    }
};