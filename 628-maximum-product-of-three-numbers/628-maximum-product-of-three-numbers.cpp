class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int m=0,l=0;
        sort(nums.begin(), nums.end());
        if(nums[0]<0 && nums[1]<0){
             m = nums[0]*nums[1]*nums[n-1];
            
        }
         l = nums[n-1]*nums[n-2]*nums[n-3];
       
        if(l> m){
            return l;
        }
        return m;
    }
};