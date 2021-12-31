// if index is not negative


// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         int n = nums.size();
//         int max_ele = *max_element(nums.begin(), nums.end());
//         vector<int>hash(max_ele+1, 0);
//         for(int i=0; i<n; i++){
//             hash[nums[i]]++;
//         }
//         // sort(nums.begin(), nums.end());
//         int maxa = 0;
//         for(int i=0; i<hash.size()-1; i++){
//             if(hash[i]!=0 and hash[i+1]!=0){
//                 maxa = max(maxa, hash[i]+hash[i+1]);
//             }
//         }
//         return maxa;
//     }
// };


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto n : nums)
            freq[n]++;
        
        int maxi = 0;
        for (auto [num, f] : freq) {
            if (freq.find(num+1) != freq.end())
                maxi = max(maxi, f + freq[num+1]);
        }
        return maxi;
    }
};