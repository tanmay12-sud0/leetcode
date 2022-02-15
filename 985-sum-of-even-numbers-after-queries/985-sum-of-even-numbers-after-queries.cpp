class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even_sum = 0;
        int n = queries.size();
        vector<int>umap;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                even_sum += nums[i];
            }
        }
        for(int i=0; i<n; i++){
            int index = queries[i][1];
            int value = queries[i][0];
            if(nums[index]%2==0){
                if(value%2==0){
                    umap.push_back(even_sum + value);
                    even_sum += value;
                }else{
                    umap.push_back(even_sum - nums[index]);
                    even_sum = even_sum - nums[index];
                }
            }else{
                if(value%2!=0){
                    umap.push_back(even_sum + value + nums[index]);
                    even_sum = even_sum + value + nums[index];
                }else{
                    umap.push_back(even_sum);
                }
            }
            nums[index] += value;
            // for(auto x : nums){
            //     cout << x << ", ";
            // }
            // cout << endl;
        }
        return umap;
    }
};