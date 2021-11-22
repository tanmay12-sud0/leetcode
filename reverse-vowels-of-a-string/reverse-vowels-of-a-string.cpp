class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int n = s.length();
        int end = n-1;
        while(start < end){
            while(start < end and s[start]!='a' and s[start] != 'e' and s[start] != 'i' and s[start]!='o' and s[start] != 'u' and s[start]!='A' and s[start] != 'E' and s[start] != 'I' and s[start]!='O' and s[start] != 'U'){
                start++;
            }
            while(start < end and s[end]!='a' and s[end] != 'e' and s[end] != 'i' and s[end]!='o' and s[end] != 'u' and s[end]!='A' and s[end] != 'E' and s[end] != 'I' and s[end]!='O' and s[end] != 'U' ){
                end--;
            }
            swap(s[start], s[end]);
            start++,end--;
        }
        return s;
    }
};