class Solution {
public:
    bool isPowerOfFour(int n) {
        int zero = 0;
        int one = 0;
        if(n<0)return false;
        while(n){
            if(n&1){
                one++;
            }else{
                zero++;
            }
            n = n>>1;
        }
        if(zero%2==0 and one==1){
            return true;
        }
        return false;
    }
};