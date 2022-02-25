class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int zero = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(arr[i] == 0){
                zero++;
            }
        }
        if(sum%3!=0){
            return false;
        }
        if(zero == n){
            return true;
        }
        int diff = sum/3;
        int tot = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            tot += arr[i];
            if(tot == diff){
                count++;
                tot = 0;
            }
        }
        if(count >= 3){
            return true;
        }
        return false;
    }
};