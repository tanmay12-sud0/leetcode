class Solution {
public:
    bool checkPowersOfThree(int n) {
        set<int>s;
        int count = 0;
        while(n){
            count++;
            int res = 1;
            int cnt = 0;
            while(res <= n){
                res *= 3;
                cnt++;
            }
            // cout << cnt << ", " << res/3 << endl;
            s.insert(--cnt);
            n = n-(res/3);
            cout << n << endl;
        }
        if(s.size() == count){
            return true;
        }
        return false;
    }
};