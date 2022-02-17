class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        
        for(auto x : rolls){
            sum += x;
        }
        int value = (mean*(n+rolls.size())) - sum;
        
        int rem = value%n;
        vector<int>hash(n, value/n);
        if(value<n){
            hash.clear();
            return hash;
        }
        if(value > n*6){
            hash.clear();
            return hash;
        }
        for(int i=0; i<n; i++){
            if(rem){
                rem--;
                hash[i]++;
            }else{
                break;
            }
        }
        return hash;
    }
};