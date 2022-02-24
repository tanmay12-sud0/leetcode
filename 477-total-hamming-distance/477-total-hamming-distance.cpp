class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int>hash(33, 0);
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            int value = nums[i];
            int pos = 0;
            while(value>0){
                hash[pos++] += value&1;
                value = value >> 1;
            }
        }
        int res = 0;
        for(auto x : hash){
            res += (x)*(n-x);
        }
        return res;
    }
};