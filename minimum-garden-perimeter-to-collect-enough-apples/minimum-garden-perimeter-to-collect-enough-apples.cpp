class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long int cnt = 0;
        for(long long int i=0; i<INT_MAX; i++){
            cnt += (12*i*i);
            if(cnt >= neededApples){
                return i*2*4;
            }
        }
        return -1;
    }
};