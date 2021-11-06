class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2){
            return len;
        }
        int in = 2;
        for(int i=2; i<len; i++){
            if(nums[i] != nums[in-2]){
                nums[in++] = nums[i];
            }
        }
        return in;
    }
};