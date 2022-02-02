class Solution {
public:
    bool checkro(unordered_map<char, int>hash, string s){
        for(auto x : s){
            if(hash.count(x)){
                hash[x]--;
                if(hash[x]==0){
                    hash.erase(x);
                }
            }
        }
        if(hash.size()==0){
            return true;
        }
        return false;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int>hash;
        unordered_map<char, int>hash2;
        vector<string>umap;
        if(words2.size()==0){
            return umap;
        }
        for(auto x : words2[0]){
            hash[x]++;
        }
        for(int i=1; i<words2.size(); i++){
            string a = words2[i];
            for(auto x : a){
                if(hash.count(x)){
                    hash[x]--;
                    if(hash[x]==0){
                        hash.erase(x);
                    }
                }
            }
            for(auto x : a){
                hash[x]++;
            }
        }
        for(auto x : hash){
            cout << x.first << ", " << x.second << endl;
        }
        for(int i=0; i<words1.size(); i++){
            string s = words1[i];
            if(checkro(hash, s)){
                umap.push_back(s);
            }
        }
        return umap;
    }
};