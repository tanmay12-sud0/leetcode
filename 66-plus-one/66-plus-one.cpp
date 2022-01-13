class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9){
            digits[n-1]++;
        }else{
            int carry = 1;
            for(int i = n-1; i>=0; i--){
                int x = carry+digits[i];
                if(x>9){
                    carry = x/10;
                    digits[i] = x%10;
                }else{
                    digits[i] = x;
                    carry = 0;
                }
            }
            if(carry){
                digits.insert(digits.begin(), carry);
            }
        }
        return digits;
    }
};