class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int pre = 0;
        int n = nums.size();
        unordered_map<int, int>hash;
        hash[0]++;
        for(int i=0; i<n; i++){
            pre += nums[i];
            int remainder = pre%k;
            if(remainder < 0){
                remainder += k;
            }
            if(hash.count(remainder)){
                count += hash[remainder];
            }
            hash[remainder]++;
        }
        return count;
    }
};