class Solution {
public:
    
    int check(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        unordered_map<int, int>hash;
        for(int i=1; i<=n; i++){
            hash[check(i)]++;
        }
        int max_so_far = INT_MIN;
        for(auto x : hash){
            max_so_far = max(max_so_far, x.second);
        }
        int cnt = 0;
        for(auto x : hash){
            if(x.second == max_so_far){
                cnt++;
            }
        }
        return cnt;
    }
};