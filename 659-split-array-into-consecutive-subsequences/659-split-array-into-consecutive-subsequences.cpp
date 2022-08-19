class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>umap, tails;
        for(auto i : nums){
            umap[i]++;
        }
        for(auto i : nums){
            if(!umap[i]){
                continue;
            }
            if(tails[i-1] > 0){
                tails[i-1]--;
                tails[i]++;
            }else if(umap[i+1] and umap[i+2]){
                umap[i+1]--;
                umap[i+2]--;
                tails[i+2]++;
            }else{
                return false;
            }
            umap[i]--;
        }
        return true;
    }
};