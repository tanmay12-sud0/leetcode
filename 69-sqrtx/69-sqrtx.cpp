class Solution {
public:
    
    int check(int x){
        int ans = 0;
        int s = 0;
        int e = x;
        while(s <= e){
            long long mid = (s+e)/2;
            if(mid*mid <= x){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
    
    int mySqrt(int x) {
        return check(x);    
    }
};