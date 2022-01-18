class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int>hash;
        for(int i=0; i<s.length(); i++){
            hash[s[i]]++;
        }
        set<int>ss;
        for(auto x : hash){
            ss.insert(x.second);
        }
        return ss.size()==1;
    }
};