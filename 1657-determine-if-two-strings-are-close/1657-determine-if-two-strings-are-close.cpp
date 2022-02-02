class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int>x1;
        unordered_map<char, int>x2;
        unordered_map<int, int>x3;
        unordered_map<char, int>x4;
        for(auto a : word1){
            x1[a]++;
        }
        for(auto a : word2){
            x2[a]++;
        }
        for(auto a : x1){
            x4[a.first]++;
        }
        for(auto a : x2){
            x4[a.first]--;
        }
        for(auto a : x4){
            if(a.second != 0){
                return false;
            }
        }
        
        
        for(auto a : x1){
            x3[a.second]++;
        }
        for(auto a : x2){
            x3[a.second]--;
        }
        for(auto a : x3){
            if(a.second != 0){
                return false;
            }
        }
        return true;
    }
};