class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 > len2){
            int diff = len1-len2;
            while(diff--){
                num2 = "0" + num2;
            }
        }else{
            int diff = len2-len1;
            while(diff--){
                num1 = "0" + num1;
            }
        }
        int carry = 0;
        string ss;
        for(int i=num1.size()-1; i>=0; i--){
            int x = ((num1[i]-'0') + (num2[i]-'0') + carry);
            ss = to_string(x%10) + ss;
            carry = x/10;
        }
        while(carry>0){
            ss = to_string(carry%10) + ss;
            carry = carry/10;
        }
        return ss;
    }
};