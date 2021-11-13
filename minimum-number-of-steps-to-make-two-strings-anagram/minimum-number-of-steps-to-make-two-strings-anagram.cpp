class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int>hash;
        for(auto x : s){
            hash[x]++;
        }
        for(auto x : t){
            if(hash.count(x)){
                hash[x]--;
            }
        }
        int count = 0;
        for(auto x : hash){
            while(x.second > 0){
                count++;
                x.second--;
            }
        }
        return count;
    }
};