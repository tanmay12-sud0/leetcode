class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count =0;
        string s;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                s = nums[i] + nums[j];
                if(i != j and s == target){
                    // nums.erase(nums.begin() + i);
                    // nums.erase(nums.begin() + j);
                    count++;
                }
            }
        }
        return count;
    }
};