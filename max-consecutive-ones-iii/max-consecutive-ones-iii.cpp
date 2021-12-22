class Solution {
public:
    
//     bool hogya(int mid, vector<int>nums, int k, int len){
//         int i=0;
//         int j = mid;
//         while(j<len){
//             if(i-1>=0 and nums[j]-nums[i-1] <= k) {
//                 return true;
//             }
//             if(i-1<0 and nums[j] <= k) {
//                 return true;
//             }
//             i++,j++;
//         }
//         return false;
//     }
    
    
    
    int longestOnes(vector<int>& A, int K) {
        int left = 0;
        int right = 0;
        int mx = 0;

        int numZeroes = 0;
        for (right= 0; right<A.size(); right++) {

            if (A[right]==0) numZeroes++;

            if (numZeroes > K) {
                if (A[left]==0) numZeroes--;
                left ++;
            }
            if (numZeroes <= K) {
                      mx = max(mx, right-left +1 );
            }
        }
        return mx;
//         int len = nums.size();
//         if(nums[0]==0){
//             nums[0]=1;
//         }else{
//             nums[0]=0;
//         }
//         for(int i=1; i<len; i++){
//             if(nums[i]==0){
//                 nums[i] = nums[i-1]+1;
//             }else{
//                 nums[i] = nums[i-1];
//             }
//         }
//         if(nums[0] ==0 and nums[len-1] == len){
//             return 0;
//         }
//         int start = 1;
//         int end = len;
//         int ans = 0;
//         while(start <= end){
//             int mid = (start+end)/2;
            
//             if(hogya(mid, nums, k, len)){
//                 ans = mid;
//                 start = mid+1;
//             }else{
//                 end = mid-1;
//             }
//         }
        
//         return ans+1;
    }
};