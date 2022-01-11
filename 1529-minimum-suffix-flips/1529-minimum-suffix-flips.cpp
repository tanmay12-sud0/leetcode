class Solution {
public:
    int minFlips(string target) {
        char next_index = '0';
        int n = target.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(target[i] == next_index){
                continue;
            }else{
                count++;
                if(next_index == '1'){
                    next_index = '0';
                }else{
                    next_index = '1';
                }
            }
        }
        return count;
    }
};