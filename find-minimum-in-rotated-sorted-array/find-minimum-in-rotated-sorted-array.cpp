class Solution {
public:
    
    int binary(vector<int>&nums, int s, int e){
        while(s<=e){
            int mid = (s+e)/2;
            if(s == e){
                return nums[s];
            }
            if(nums[mid] < nums[mid+1] and nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid] >= nums[0]){
                s = mid+1;
            }
            else if(nums[mid] < nums[nums.size()-1]){
                e = mid-1;
            }
        }
        return -1;
    }
    
    int findMin(vector<int>& nums) {
       int len = nums.size();
        int count = 0;
        int count2 = 0;
        for(int i=0; i<len-1; i++){
            if(nums[i] < nums[i+1]){
                count++;
            }else{
                count2++;
            }
        }
        if(count == len-1){
            return nums[0];
        }
        if(count2 == len-1){
            return nums[nums.size()-1];
        }
        
        return binary(nums, 0, len-1);
    }
};