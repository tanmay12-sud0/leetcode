class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row = nums.size();
        unordered_map<int, vector<int>>umap;
        int maxKey = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<nums[i].size(); j++){
                umap[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);
            }
        }
        vector<int>hash;
        for(int i=0; i<=maxKey; i++){
             for (auto x = umap[i].rbegin(); x != umap[i].rend(); x++) {
                hash.push_back(*x); 
            }
        }
        return hash;
    }
};
