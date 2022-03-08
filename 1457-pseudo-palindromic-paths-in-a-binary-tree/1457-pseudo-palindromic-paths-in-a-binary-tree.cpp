class Solution {
public:
    void rec(TreeNode* root) {
        if (!root)
            return;
        
        m[root->val]++;
        
        if (!root->left && !root->right) {
            int odd = 0;
            for (auto a : m)
                if (a.second % 2 == 1)
                    odd++;

            if (odd <= 1)
                res++;
        }
        
        rec(root->left);
        rec(root->right);
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        rec(root);
        return res;
    }
    
private:
    int res = 0;
    unordered_map<int, int> m;
};

// class Solution {
// public:
    
//     void solve(TreeNode* &root, int &cnt, vector<int>&hash){
//         if(root == NULL){
//             return;
//         }
//         hash.push_back(root->val);
//         if(root->left== NULL and root->right==NULL){
//             vector<int>umap(10, 0);
//             for(auto x : hash){
//                 umap[x]++;
//                 // cout << x << " ";
//             }
//             int ones = 0;
//             bool f = true;
//             for(auto x : umap){
//                 if(x%2==0){
//                     continue;
//                 }else{
//                     ones++;
//                     if(ones>1){
//                         f = false;
//                         break;
//                     }
//                 }
//             }
//             if(f){
//                 cnt++;
//             }
//         }
//         solve(root->left, cnt, hash);
//         solve(root->right, cnt, hash);
//         hash.pop_back();
//         return;
//     }
    
    
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int>hash;
//         int cnt = 0;
//         solve(root, cnt, hash);
//         return cnt;
//     }
// };