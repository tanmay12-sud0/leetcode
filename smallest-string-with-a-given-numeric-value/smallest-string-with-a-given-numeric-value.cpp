class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        while(n > 0){
            int i = 26;
            while(k-i < n-1){
                i--;
            }
            k -= i;
            s += i+'a'-1;
            n--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};