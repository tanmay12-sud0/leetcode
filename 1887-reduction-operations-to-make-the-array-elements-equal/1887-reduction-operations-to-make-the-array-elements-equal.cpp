class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int small = nums[0];
        int oper = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == small){
                oper += cnt;
                continue;
            }
            cnt++;
            small = nums[i];
            oper += cnt;
        }
        return oper;
    }
};