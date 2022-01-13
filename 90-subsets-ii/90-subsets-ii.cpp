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
        sort(ss.begin(), ss.end());
        return ss;
    }
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>s;
        set<vector<int>>ss;
        
        for(int i=0; i<pow(2,n); i++){
            ss.insert(subs(i, nums));
        }
        for(auto x : ss){
            s.push_back(x);
        }
        return s;
    }
};

      