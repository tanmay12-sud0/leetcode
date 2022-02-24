class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>umap;
        for(int i=0; i<=n; i++){
            umap.push_back(__builtin_popcount(i));
        }
        return umap;
    }
};