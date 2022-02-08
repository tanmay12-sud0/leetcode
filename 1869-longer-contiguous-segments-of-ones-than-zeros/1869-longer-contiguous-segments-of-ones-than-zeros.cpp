class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.length();
        vector<int>hash1(n, 0);
        vector<int>hash0(n, 0);
        s[0]=='0'? hash0[0]=1: hash1[0]=1;
        for(int i=1; i<n; i++){
            if(s[i]=='1'){
                hash0[i] = 0;
            }else{
                hash0[i] = (1+hash0[i-1]);
            }
        }
        for(int i=1; i<n; i++){
            if(s[i]=='0'){
                hash1[i] = 0;
            }else{
                hash1[i] = (1+hash1[i-1]);
            }
        }
        int max0 = 0;
        int max1 = 0;
        for(auto x : hash0){
            max0 = max(max0, x);
            // cout << x << ", ";
        }
        cout << endl;
        for(auto x : hash1){
            max1 = max(max1, x);
            // cout << x << ", ";
        }
        cout << max0 <<",," << max1 << endl;
        if(max1 > max0){
            return true;
        }
        return false;
    }
};