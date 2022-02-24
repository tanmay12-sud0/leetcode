class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(int i=0; i<n; i++){
            xorr = xorr^nums[i];
        }
        int set=0;
        int xxx = xorr;
        while((xorr&1) != 1){
            set++;
            xorr = xorr>>1;
        }
        vector<int>umap;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&(1<<set)){
                umap.push_back(nums[i]);
            }
        }
        int x = 0;
        for(auto nbr : umap){
            x = x^nbr;
        }
        int y = xxx^x;
        vector<int>xx{min(x, y), max(x, y)};
        return xx;
    }
};