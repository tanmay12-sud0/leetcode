class Solution {
public:
    int reverse(int x) {
        long long int rev = 0;
        while(x){
            rev = rev*10 + x%10;
            x = x/10;
        }
        if((rev< pow(2,31)-1) && (rev > -pow(2, 31))){
            return rev;
        }else{
            return 0;
        }
        
    }
};