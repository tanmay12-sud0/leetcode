class Solution {
public:
    void minm(int n,int& sub, int& div){
        while(n!=0){
            if(n%2==1){
                n--;
                sub++;
            }
            else{
                n /=2;
                div++;
            }
        }
            
    }
    
    int minOperations(vector<int>& nums) {
        int ans=0;
        int max_div=0;
         for(int n: nums){
             int sub=0, div=0;
             minm(n, sub, div);
             ans+= sub;
             max_div=max(max_div,div);
         }
        return ans+max_div;
    }
};



// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             if(nums[i]%2!=0){
//                 count++;
//                 nums[i]--;
//             }
//         }
//         // cout << count << endl;
        
//         for(auto x : nums){
//             cout << x << ", ";
//         }
//         cout << endl;
        
//         for(int i=0; i<n; i++){
//             int x = nums[i]/2;
//             count += x;
//             while(x--){
//                 nums[i] = nums[i]/2;
//             }
//         }
        
//         for(auto x : nums){
//             cout << x << ", ";
//         }
//         cout << endl;
//         // cout << count << endl;
        
//         for(int i=0; i<n; i++){
//             if(nums[i]==1){
//                 count++;
//             }
//         }
        
//         for(auto x : nums){
//             cout << x << ", ";
//         }
//         cout << endl;
        
//         // cout << count << endl;
//         return count;
//     }
// };