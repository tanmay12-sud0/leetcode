class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        if(n == 1 or n == 0){
            return {};
        }
        vector<int>pre(n, 0);
        vector<int>suff(n, 0);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]*nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1]*nums[i];
        }

        vector<int>umap(n, 0);
        umap[0] = suff[1];
        umap[n-1] = pre[n-2];
        for(int i=1; i<n-1; i++){
            umap[i] = pre[i-1]*suff[i+1];
        }
        return umap;
    }
};