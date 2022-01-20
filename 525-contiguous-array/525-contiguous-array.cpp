class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }
        int pre = 0;
        int max_so_far = 0;
        unordered_map<int, int>umap;
        for(int i=0; i<n; i++){
            pre += nums[i];
            if(pre == 0){
                max_so_far = max(max_so_far, i+1);
            }
            if(umap.count(pre)){
                max_so_far = max(max_so_far, i-umap[pre]);
            }else{
                umap[pre] = i;
            }
        }
        return max_so_far;
    }
};