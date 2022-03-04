class Solution {
public:
    int findComplement(int num) {
        string s;
        while(num>0){
            int value = num&1;
            if(value){
                s = '0' + s;
            }else{
                s = '1' + s;
            }
            num = num>>1;
        }
        int res = 0;
        int x = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='1'){
                res += pow(2, x);
            }
            x++;
        }
        return res;
    }
};