class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // 0(n) algorithm
        
        
        int num = -1;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(num == nums[i]){
                count++;
            }else if(count == 0){
                num = nums[i];
            }else{
                count--;
            }
        }
        return num;
    }
};