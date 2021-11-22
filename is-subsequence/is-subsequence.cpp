class Solution {
public:
    bool isSubsequence(string s, string t) {
        // int start = 0;
        int end = 0;
        int n = t.length();
        for(int i=0; i<n; i++){
            if(t[i] == s[end]){
                end++;
            }
        }
        if(end == s.length()){
            return true;
        }
        return false;
    }
};