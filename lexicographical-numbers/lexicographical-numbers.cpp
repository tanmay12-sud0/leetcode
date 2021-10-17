bool compFunction (int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1<s2;
    }

class Solution {
public:
    
    
    vector<int> lexicalOrder(int n) {
        vector<int>umap;
        for(int i=1; i<=n; i++){
            umap.push_back(i);          
        }
        sort(umap.begin(), umap.end(), compFunction);
        return umap;
    }
};