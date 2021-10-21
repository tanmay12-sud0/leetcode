class Solution {
public:
    
    vector<int> subs(int i, vector<int>nums){
        vector<int> ss;
        int j=0;
        while(i>0){
            int last_digit = (i&1);
            if(last_digit){
                ss.push_back(nums[j]);
            }
            j++;
            i = i>>1;
        }
        return ss;
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>s;
        for(int i=0; i<pow(2,n); i++){
            s.push_back(subs(i, nums));
        }
        return s;
    }
};