class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e= 1, i=1,o=1,u=1;
        int sum = 0;
        while(--n){
            u = 1;
            o = o + u;
            i = i + o;
            e = e + i;
            a = a + e;
        }
        sum += a;
        sum += e;
        sum += i;
        sum += o;
        sum += u;
        return sum;
    }
};