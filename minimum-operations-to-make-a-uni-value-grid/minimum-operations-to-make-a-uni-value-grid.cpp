// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {
//         int n = grid.size();
//         if(n==1){
//             return 0;
//         }
//         vector<int>umap;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 umap.push_back(grid[i][j]);
//             }
//         }
        
//         sort(umap.begin(), umap.end());
//         int median = umap[n];
//         // 
//         cout << median << endl;
//         float total = 0;
//         for(int i=0; i<umap.size(); i++){
//             total += float(abs(median-umap[i]))/float(x);
//         }
//         if(total == int(total)){
//             return total;
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                nums.push_back(grid[i][j]);
        sort(nums.begin(),nums.end());
        int target=nums[m*n/2],ans=0;
        for(int i=m*n-1;i>=0;i--){
            if(abs(nums[i]-target)%x!=0)
                return -1;
            else
                ans+=abs(nums[i]-target)/x;  
        }
        return ans;
    }
};