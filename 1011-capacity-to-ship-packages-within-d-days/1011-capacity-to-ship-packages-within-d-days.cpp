class Solution {
public:
    bool hogya(vector<int>& weights, int days, int mid, int n){
        int sum = 0;
        int count = 0;
        for(int i=0; i<n;i++){
            sum += weights[i];
            if(weights[i]>mid){
                return false;
            }
            if(sum > mid){
                count++;
                sum = weights[i];
            }
        }
        if(count < days){
            return true;
        }
       return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total_weight = 0;
        int n = weights.size();
        for(int i=0; i<n; i++){
            total_weight += weights[i];
        }
        int start = 1;
        int ans  = 0;
        int end = total_weight;
        while(start <= end){
            int mid = (start+end)/2;
            if(hogya(weights, days,mid, n)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};