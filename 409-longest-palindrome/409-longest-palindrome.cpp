class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        unordered_map<char, int>hash;
        for(auto x : s){
            hash[x]++;
        }
        int tan = 0;
        for(auto x : hash){
            len += 2*(x.second/2);
            tan += x.second%2;
            
        }
        if(tan){
            return len+1;
        }
        return len;
    }
};