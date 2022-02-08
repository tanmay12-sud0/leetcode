class Solution {
public:
    int maxPower(string s) {
        int max_so_far = 0;
        int n = s.length();
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                cnt++;
            }else{
                max_so_far = max(cnt, max_so_far);
                cnt = 0;
            }
        }
        max_so_far = max(cnt, max_so_far);
        return max_so_far+1;
    }
};