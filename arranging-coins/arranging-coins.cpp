class Solution {
public:
    int arrangeCoins(int n) {
        long long sum =0;
        if(n == 1){
            return 1;
        }
        for(int i=1; i<=n; i++){
            sum += i;
            if(sum == n){
                return i;
            }
            if(sum > n){
                return i-1;
            }
        }
        return -1;
    }
};