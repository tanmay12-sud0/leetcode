class Solution {
public:
    
    bool hogya(int mid, vector<int>quantity, int n){
        int cnt = 0;
        for(int i=0; i<quantity.size(); i++){
            cnt += quantity[i]/mid;
            if(quantity[i]%mid!=0){
                cnt++;
            }
        }
        if(cnt <= n){
            return true;
        }
        return false;
    }
    
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int len = quantities.size();
        int start = 1;
        int end = INT_MAX;
        int ans = 0;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(hogya(mid, quantities, n)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};