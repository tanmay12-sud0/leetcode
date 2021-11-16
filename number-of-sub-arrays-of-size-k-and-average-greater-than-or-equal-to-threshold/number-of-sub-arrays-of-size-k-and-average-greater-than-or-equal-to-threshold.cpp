class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int len = arr.size();
        if(len < k){
            return count;
        }
        int avg = 0;
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += arr[i];
        }
        if(sum/k >= threshold){
            count++;
        }
        int i = k;
        int j = 0;
        while(i<len){
            sum = sum + arr[i] - arr[i-k];
            if(sum/k >= threshold){
                count++;
            }
            i++;
        }
        return count;
    }
};