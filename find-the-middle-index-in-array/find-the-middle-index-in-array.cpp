class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        vector<int>pre(n, 0);
        vector<int>suff(n, 0);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = nums[i]+pre[i-1];
        }
        for(int i=n-2; i>=0; i--){
            suff[i] = nums[i]+suff[i+1];
        }
        if(suff[1]==0){
            return 0;
        }
        for(int i=1; i<n-1; i++){
            if(pre[i-1] == suff[i+1]){
                return i;
            }
        }
        if(pre[n-2]==0){
            return n-1;
        }
        return -1;
    }
};