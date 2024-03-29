class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] > n or nums[i] <= 0){
                nums[i] = n+1;
            }
        }

        for(int i=0; i<n; i++){
            int id = abs(nums[i]);
            if(id > n){
                continue;
            }else{
                id--;
                if(nums[id]>=0){
                    nums[id] = -nums[id];
                }
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};