class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int y = x;
        long long int a = 0;
        while(y){
            a = a*10 + (y%10);
            y /= 10;
        }
        return a==x;
    }
};