class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int>hash;
        int cnt = 0;
        int max_len =0;
        int start =0;
        for(int i=0; i<s.length(); i++){
            if(hash.count(s[i]) and hash[s[i]] >= start){
                start = hash[s[i]] + 1;
                cnt= i-hash[s[i]];
                hash[s[i]] = i;
                max_len = max(max_len, cnt);
            }else{
                hash[s[i]] = i;
                cnt++;
                max_len = max(max_len, cnt);
            }
        }
        max_len = max(max_len, cnt);
        return max_len;
    }
};