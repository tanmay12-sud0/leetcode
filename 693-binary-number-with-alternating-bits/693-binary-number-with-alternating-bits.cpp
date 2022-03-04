class Solution {
public:
    bool hasAlternatingBits(int n) {
        int value = n&1;
        n = n>>1;
        while(n){
            int x = n&1;
            if(x == value){
                return false;
            }
            else{
                if(value == 1){
                    value = 0;
                }else{
                    value = 1;
                }
            }
            n = n>>1;
        }
        return true;
    }
};