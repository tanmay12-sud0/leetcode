class Solution {
public:
    int max_so_far = 0;
    void solve(vector<int>&nums, int idx, int n, vector<int>hash){
        if(idx == n){
            int xors = 0;
            for(auto x : hash){
                cout << x << " ";
                xors ^= x;
            }
            cout << endl;
            max_so_far += xors;
            return;
        }
        
        solve(nums, idx+1, n, hash);
        hash.push_back(nums[idx]);
        solve(nums, idx+1, n, hash);
        return;
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        vector<int>hash;
        int idx = 0;
        int n = nums.size();
        solve(nums, idx, n, hash);
        return max_so_far;
    }
};