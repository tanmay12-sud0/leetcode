class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int>hash;
        for(auto x : word1){
            hash[x]++;
        }
        for(auto x : word2){
            hash[x]--;
        }
        for(auto x : hash){
            if(abs(x.second)>3){
                return false;
            }
        }
        return true;
    }
};