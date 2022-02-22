class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n =nums.size();
        vector<int>hash1;
        vector<int>hash2;
        for(int i=0; i<n; i++){
            if(i%2==0){
                hash1.push_back(nums[i]);
            }else{
                hash2.push_back(nums[i]);
            }
        }
        sort(hash1.rbegin(), hash1.rend());
        sort(hash2.begin(), hash2.end());
        vector<int>umap;
        for(int i=0; i<n; i++){
            if(i%2==0){
                umap.push_back(hash1.back());
                hash1.pop_back();
            }else{
                umap.push_back(hash2.back());
                hash2.pop_back();                
            }
        }
        return umap;
    }
};