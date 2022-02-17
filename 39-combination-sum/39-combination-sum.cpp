class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};







// class Solution {
// public:
        
//         set<vector<int>>hash;
        
//         void checkvalue(vector<int>& candidates, int target, int sum, int i, int n, vector<int>umap){
//                 if(i==n){
//                         return;
//                 }
//                 if(sum == target){
//                         hash.insert(umap);
//                 }
//                 if(sum <= target){
//                         umap.push_back(candidates[i]);
//                         cout << candidates[i] << endl;
//                         checkvalue(candidates, target, sum+candidates[i], i, n, umap);
//                                         umap.pop_back();

                        
//                 }
//                 checkvalue(candidates, target, sum, i+1, n, umap);
//                 return;
//         }
        
        
        
        
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//             vector<int>umap;
//             int n = candidates.size();
//             int sum = 0;
//                 checkvalue(candidates, target, sum, 0, n, umap);
//             vector<vector<int>>value;
//             for(auto x : hash){
//                     value.push_back(x);
//             }
//             return value;
//     }
// };