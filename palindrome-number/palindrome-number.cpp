class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int l = x;
        long int rev = 0;
        while(x){
            rev = rev*10 + x%10;
            x = x/10;
        }
       
        return rev == l;
    }
};