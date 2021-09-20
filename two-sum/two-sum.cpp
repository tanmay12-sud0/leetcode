class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int>umap;
        vector<int>tan;
        for(int i=0; i<nums.size(); i++){
           if(umap.count(target-nums[i])){
               tan.push_back(umap[target-nums[i]]);
               tan.push_back(i);
           }else{
               umap[nums[i]] = i;
           }
        }
        
        return tan;
    }
};



