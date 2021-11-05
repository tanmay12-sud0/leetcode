class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(binary_search(nums.begin(), nums.end(), target)){
            auto x = lower_bound(nums.begin(), nums.end(), target);
            return x-nums.begin();
            
        }else{
            return -1;
        }
        return -1;
    }
};