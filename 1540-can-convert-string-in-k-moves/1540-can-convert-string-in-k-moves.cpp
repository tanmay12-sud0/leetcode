class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        unordered_map<int, int>hash;
        unordered_set<int>umap;
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i] == t[i]){
                continue;
            }
            int a = ((t[i]-'a')-(s[i]-'a') + 26)%26;
            hash[a]++;
        }
        for(auto x : hash){
            cout << x.first << ", " << x.second << endl;
        }
        for(auto x : hash){
            int move = (k/26);
            if(k%26 and x.first<=k%26){
                move++;
            }
            cout << move << endl;
            if(move < x.second or umap.count(x.first)){
                return false;
            }
            umap.insert(x.first);
            // hash.erase(x.first);
        }
        return true;
    }
    
};