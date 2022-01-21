class Solution {
public:
    int minOperations(int n) {
        int cnt = 0;
        int sum = 1;
        while(sum <= n){
            cnt += (n-sum);
            sum += 2;
        }
        return cnt;
    }
};