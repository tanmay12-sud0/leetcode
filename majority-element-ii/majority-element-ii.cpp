class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>hash;
        vector<int>ss;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        for(auto x : hash){
            if(x.second >= ((nums.size()/3)+1)){
                ss.push_back(x.first);
            }
        }
        return ss;
    }
};