class Solution {
public:
    bool hogya(vector<int>nums, int mid, int n, int maxOperations){
        for(int i=0; i<n; i++){
            maxOperations -= nums[i]/mid;
            if(nums[i]%mid==0) maxOperations++;
        }
        if(maxOperations>=0){
            return true;
        }
        return false;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int total_sum = 0;
        int n = nums.size();
        int ans = 0;
        int start = 1;
        int end = INT_MAX;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(hogya(nums, mid, n, maxOperations)){
                ans = mid; 
                end = mid-1;
            }else{
                start = mid+1;
               
            }
        }
        return ans;
    }
};