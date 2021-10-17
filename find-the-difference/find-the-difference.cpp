class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0;
        int sum2=0;
        for(int i=0; i<s.length(); i++){
            sum1 += s[i]-'a'+1;
        }
        for(int i=0; i<t.length(); i++){
            sum2 += t[i]-'a'+1;
        }
        char ch = 'a' + sum2 - sum1-1;
        return ch;
    }
};