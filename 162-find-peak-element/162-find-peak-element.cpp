class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return 0;
        }
        if(nums[1] < nums[0]){
            return 0;
        }
        if(nums[len-1] > nums[len-2]){
            return len-1;
        }
        int start = 0;
        int end = len-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid+1] > nums[mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
};