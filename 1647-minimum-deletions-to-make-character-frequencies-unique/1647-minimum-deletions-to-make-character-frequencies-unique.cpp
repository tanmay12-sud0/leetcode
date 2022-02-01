class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>hash;
        int n = s.length();
        for(int i=0; i<n; i++){
            hash[s[i]]++;
        }
        set<int>umap;
        int cnt = 0;
        for(auto x : hash){
            char a = x.first;
            int p = x.second;
            while(umap.count(p)){
                p--;
            }
            cnt += (x.second-p);
            if(p)umap.insert(p);
        }
        return cnt;
    }
};