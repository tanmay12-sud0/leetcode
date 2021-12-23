class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long int>top(n,0);
        vector<long long int>bottom(n,0);
        top[0]=grid[0][0];
        bottom[n-1]=grid[1][n-1];
        for(int i=1;i<n;i++){
            top[i]+=top[i-1]+grid[0][i];
        }
        for(int i=n-2;i>=0;i--){
            bottom[i]+=bottom[i+1]+grid[1][i];
        }
       long long int ans=LLONG_MAX;
        for(int i=0;i<n;i++){
           long long int topSum=top[n-1]-top[i];
           long long int bottomSum=bottom[0]-bottom[i];
            ans=min(ans,max(topSum,bottomSum));
        }
        return ans;
    }
};


// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int n = grid[0].size();
//         for(int i=n-2; i>=0; i--){
//             grid[0][i] = grid[0][i] + grid[0][i+1];
//         }
//         for(int i=1; i<n; i++){
//             grid[1][i] = grid[1][i] + grid[1][i-1];
//         }
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<n; j++){
//                 cout << grid[i][j] << ", ";
//             }
//             cout << endl;
//         }
//         int min_so_far = INT_MAX;
//         for(int i=0; i<n; i++){
//             int sum1=0;
//             int sum2 = 0;
//             if(i-1>=0){
//                 sum2 = grid[1][i-1];
//             }
//             if(i+1<n){
//                 sum1 = grid[0][i+1];
//             }
//             min_so_far = min(min_so_far, max(sum1, sum2));
//         }
//         return min_so_far;
//     }
// };