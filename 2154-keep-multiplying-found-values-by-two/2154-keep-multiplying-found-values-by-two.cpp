class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while(1){
            auto it = binary_search(nums.begin(), nums.end(), original);
        if(!it){
            return original;
        }else{
            original *= 2; 
            }
        }
        return original;
    }
};