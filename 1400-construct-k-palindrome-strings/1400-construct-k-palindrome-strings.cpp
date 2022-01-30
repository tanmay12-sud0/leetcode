class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int>hash;
        if(s.length() < k){
            return false;
        }
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            hash[s[i]]++;
        }
        for(auto x : hash){
            if(x.second%2 != 0){
                cnt++;
            }
        }
        if(cnt > k){
            return false;
        }
        return true;
    }
};