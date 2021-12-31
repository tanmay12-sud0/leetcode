class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char, unordered_set<int>>hash;
        for(int i=0; i<s1.length(); i++){
            hash[s1[i]].insert(i);
        }
        int sum = 0;
        for(int i=0; i<s2.length(); i++){
            if(!hash.count(s2[i])){
                return false;
            }
            if(!hash[s2[i]].count(i)){
                sum++;
            }
        }
        if(sum == 2 or sum == 0){
            return true;
        }
        return false;
    }
};