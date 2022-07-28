class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>umap(26,0);
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            umap[s[i]-'a']++;
            umap[t[i]-'a']--;
        }
        for(int i=0; i<umap.size(); i++){
            if(umap[i] != 0){
                return false;
            }
        }
        return true;
    }
};