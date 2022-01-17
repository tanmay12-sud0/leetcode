class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int>hash2;
        int n = nums.size();
        int cnt = 0;
        int aa = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                hash2[nums[i]*nums[j]]++;
            }
        }
        for(auto x : hash2){
                int a = x.second;
                cnt += 8*((a * (a-1))/2);
        }
        return cnt;
    }
};