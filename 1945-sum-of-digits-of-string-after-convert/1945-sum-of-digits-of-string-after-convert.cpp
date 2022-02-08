class Solution {
public:
    int getLucky(string s, int k) {
        string xx;
        int n = s.length();
        for(int i=0; i<n; i++){
            int tan = s[i] - 'a' + 1;
            xx += to_string(tan);
        }
        int cnt = 0;
        int sum = 0;
        while(cnt < k){
            cnt++;
            sum = 0;
            for(int i=0; i<xx.length(); i++){
                sum += (xx[i]-'0');
            }
            xx = to_string(sum);
        }
        return sum;
    }
};