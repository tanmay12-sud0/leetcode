class Solution {
public:
    bool hogya(vector<int>nums, int mid, int n, int maxOperations){
        // int cuts = -1;
        for(int i=0; i<n; i++){
            maxOperations -= nums[i]/mid;
            if(nums[i]%mid==0) maxOperations++;
        }
        // cout << "mid " << mid << ", " << cuts << endl;
        if(maxOperations>=0){
            return true;
        }
        return false;
    }
    
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int total_sum = 0;
        int n = nums.size();
        // for(int i=0; i<n; i++){
        //     total_sum += nums[i];
        // }
        int ans = 0;
        int start = 1;
        int end = INT_MAX;
        while(start <= end){
            int mid = end - (end- start)/2;
            if(hogya(nums, mid, n, maxOperations)){
                ans = mid; 
                 // start = mid+1;
                end = mid-1;
            }else{
             // end = mid-1;
                start = mid+1;
               
            }
        }
        return ans;
    }
};