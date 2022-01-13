class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        set<int>s;
        for(int i=0; i<len; i++){
            s.insert(nums[i]);
        }
        return s.size() != len;
    }
};