class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int>& candidates,vector<int> &combination,int pos,int target){
        if(!target){
            res.emplace_back(combination);
        }
        for(int i = pos; i < candidates.size() && target >= candidates[i]; i++){
            if(i > pos && candidates[i] == candidates[i-1]) continue;
            combination.emplace_back(candidates[i]);
            helper(res,candidates,combination,i + 1,target - candidates[i]);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        helper(res,candidates,combination,0,target);
        return res;
    }
};























// class Solution {
// public:
        
// //         set<vector<int>>hash;
// //         void checkvalue(vector<int>& candidates, int target, int sum, int i, int n, vector<int>&umap){
// //                 if(i==n){
// //                         return;
// //                 }
                
// //                 if(sum <= target){
// //                         umap.push_back(candidates[i]);
// //                         checkvalue(candidates, target, sum+candidates[i], i+1, n, umap);
// //                                         umap.pop_back();
// //                 }
// //                 checkvalue(candidates, target, sum, i+1, n, umap);
// //             if(sum == target){
// //                     hash.insert(umap);
// //                     return;
// //             }
// //             return;
// //         }
//     void helper(vector<vector<int>> &res,vector<int>& candidates,vector<int> &combination,int pos,int target){
//         if(!target){
//             res.emplace_back(combination);
//         }
//         for(int i = pos; i < candidates.size() && target >= candidates[i]; i++){
//             if(i > pos && candidates[i] == candidates[i-1]) continue;
//             combination.emplace_back(candidates[i]);
//             helper(res,candidates,combination,i + 1,target - candidates[i]);
//             combination.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {                  
//             sort(candidates.begin(), candidates.end());
//             // vector<int>umap;
//             int n = candidates.size();
//             // int sum = 0;
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>> res;
//         vector<int> combination;
//             helper(res,candidates,combination,0,target);
//             // vector<vector<int>>value;
//             for(auto x : hash){
//                     value.push_back(x);
//             }
//             return value;
//     }
// };

