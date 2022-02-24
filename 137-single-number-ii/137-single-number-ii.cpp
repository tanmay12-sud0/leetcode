class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bitSum=0;
            for(int num:nums){
                bitSum+=((num>>i)&1);
            }
            if(bitSum%3){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};





// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();
//         map<int, int>hash;
//         for(int i=0; i<n; i++){
//             int value = abs(nums[i]);
//             int j = 0;
//             while(value>0){
//                 hash[j++] += value&1;
//                 value = value >> 1;
//             }
//         }
//         for(auto x : hash){
//             cout << x.first << "  " << x.second << endl;
//         }
//         int pow = 1;
//         int res = 0;
        
//         for(auto x : hash){
//             res += (x.second%3)*pow;
//             pow *= 2;
//         }
//         return res;
//     }
// };