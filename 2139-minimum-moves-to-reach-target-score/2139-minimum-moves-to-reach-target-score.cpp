class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while(target != 1){
            if(target%2 == 0 and maxDoubles>0){
                target /= 2;
                cnt++;
                maxDoubles--;
            }else if(maxDoubles == 0){
                cnt += (target-1);
                break;
            }
            else{
                cnt++;
                target--;
            }
        }
        return cnt;
    }
};