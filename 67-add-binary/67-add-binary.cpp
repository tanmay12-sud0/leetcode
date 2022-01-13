class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int i = len1-1;
        int j = len2-1;
        string s;
        int carry = 0;
        while(i>=0 or j>=0){
            int p = 0;
            int q = 0;
            if(i>=0){
                p = a[i]-'0';
            }
            if(j>=0){
                q = b[j]-'0';
            }
            int sum = p+q+carry;
            if(sum <= 1){
                s += to_string(sum);
                carry = 0;
            }else{
                if(sum == 2){
                    carry = 1;
                    s += '0';
                }
                if(sum == 3){
                    carry = 1;
                    s += '1';
                }
            }
            i--,j--;
        }
        if(carry){
            s += to_string(carry);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};