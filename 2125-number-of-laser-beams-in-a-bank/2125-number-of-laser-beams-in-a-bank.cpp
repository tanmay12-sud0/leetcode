class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int>hash;
        for(int i=0; i<n; i++){
            string s = bank[i];
            int count = 0;
            for(auto x : s){
                if(x=='1'){
                    count++;
                }
            }
            if(count){
                hash.push_back(count);
            }
        }
        // for(auto x : hash){
        //     cout << x << endl;
        // }
        int sum = 0;
        if(hash.size()==0){
            return 0;
        }
        for(int i=0; i<hash.size()-1; i++){
            sum += hash[i]*hash[i+1];
        }
        return sum;
    }
};