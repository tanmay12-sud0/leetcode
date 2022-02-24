class Solution {
public:
    int binaryGap(int n) {
        int max_so_far = 0;
        int index = -1;
        int pos = 0;
        while(n){
            if(n&1==1 and index == -1){
                index = pos; 
            }else if(n&1==1 and index != -1){
                max_so_far = max(max_so_far, pos-index);
                index = pos;
            }
            pos++;
            n = n>>1;
        }
        return max_so_far;
    }
};