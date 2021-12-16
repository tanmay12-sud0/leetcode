class Solution {
public:
    
    bool hogya(int days , int m, int k, vector<int>bloomDay){
        int cnt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                cnt++;
                if(cnt == k){
                    m--;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return m<=0;
    }
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k > n){
            return -1;
        }
        int start = 1;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(hogya(mid, m, k, bloomDay)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};