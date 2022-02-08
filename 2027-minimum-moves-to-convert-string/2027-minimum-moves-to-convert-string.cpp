class Solution {
public:
    int minimumMoves(string s) {
        int len = s.length();
        int cnt=0;
        for(int i=0; i<len; i++){
            if(s[i]=='X'){
                cnt++;
                for(int j=i; j<i+3 and j<len; j++){
                    s[j] = 'O';
                }
            }
        }
        cout << s << endl;
        return cnt;
    }
};