class Solution {
public:
        
        set<vector<int>>hash;
        
        void checkvalue(vector<int>& candidates, int target, int sum, int i, int n, vector<int>umap){
                if(i==n){
                        return;
                }
                if(sum == target){
                        hash.insert(umap);
                }
                if(sum <= target){
                        umap.push_back(candidates[i]);
                        cout << candidates[i] << endl;
                        checkvalue(candidates, target, sum+candidates[i], i, n, umap);
                                        umap.pop_back();

                        
                }
                checkvalue(candidates, target, sum, i+1, n, umap);
                return;
        }
        
        
        
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int>umap;
            int n = candidates.size();
            int sum = 0;
                checkvalue(candidates, target, sum, 0, n, umap);
            vector<vector<int>>value;
            for(auto x : hash){
                    value.push_back(x);
            }
            return value;
    }
};