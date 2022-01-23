class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mina = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            mina = min(mina, nums[i]);
        }
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            cnt += (nums[i]-mina);
        }
        return cnt;
    }
};