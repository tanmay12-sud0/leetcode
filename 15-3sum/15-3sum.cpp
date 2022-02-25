class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if(n<3){
            return {};
        }
        set<vector<int>>ss;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            int a = i;
            int b = i+1;
            int c = n-1;
            while(b<c){
               int sums = nums[a]+nums[b]+nums[c];
                if(sums == 0){
                    ss.insert({nums[a], nums[b], nums[c]});
                    b++,c--;
                }else if(sums > 0){
                    c--;
                }else{
                    b++;
                }
            }
        }
        for(auto x : ss){
            result.push_back({x[0], x[1], x[2]});
        }
        return result;
    }
};