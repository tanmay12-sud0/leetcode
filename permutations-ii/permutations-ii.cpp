class Solution {
public:
    
     vector<vector<int>>umap;
    set<vector<int>>ss;
void permutation(vector<int>&nums, int i, int n){
    if(i == n){
        // umap.push_back({nums.begin(), nums.end()});
        ss.insert(nums);
        return;
    }
    for(int x=i;x<n; x++){
        swap(nums[i], nums[x]);
        permutation(nums, i+1, n);
        swap(nums[i], nums[x]);
    }
}
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         int n = nums.size();
        permutation(nums, 0, n);
        for(auto x : ss){
            umap.push_back(x);
        }
        return umap;
    }
};

