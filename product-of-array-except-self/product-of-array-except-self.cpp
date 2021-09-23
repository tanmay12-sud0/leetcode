class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,0);
        vector<int>surfix(n, 0);
        vector<int>finals(n, 0);
        prefix[0] = nums[0];
        surfix[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]*nums[i];
        }
        for(int i=n-2; i>=0; i--){
            surfix[i] = surfix[i+1]*nums[i];
        }
        finals[0] = surfix[1];
        finals[n-1] = prefix[n-2];
        for(int i=1; i<n-1; i++){
           finals[i] = prefix[i-1]*surfix[i+1]; 
        }
        return finals;
    }
};