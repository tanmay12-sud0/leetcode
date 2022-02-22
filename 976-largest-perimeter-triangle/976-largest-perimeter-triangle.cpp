class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_so_far = 0;
        for(int i=0; i<nums.size()-2; i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a+b>c){
                max_so_far = max(max_so_far, a+b+c);
            }
        }
        return max_so_far;
    }
};