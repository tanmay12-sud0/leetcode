class Solution {
public:
    unordered_map<int, vector<int>>umap;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            umap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target){
        int x = rand()%(umap[target].size());
        return umap[target][x];
    }
};
