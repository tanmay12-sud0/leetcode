class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ss;
        if(n <= 3){
            return ss;
        }
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        for(long long int i=0; i<n-3; i++){
            for(long long int j=i+1; j<n-2; j++){
                long long int start = j+1;
                long long int end = n-1;
                while(start < end){
                   // long long int sum = nums[i]+nums[j]+nums[start]+nums[end];
                    if(nums[start]+nums[end] == target-nums[i]-nums[j]){
                        vector<int>v{nums[i], nums[j], nums[start], nums[end]};
                        s.insert(v);
                        start++, end--;
                    }
                    else if(nums[start]+nums[end] > target-nums[i]-nums[j]){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        
        for(auto x : s){
            ss.push_back(x);
        }
        return ss;
    }
};