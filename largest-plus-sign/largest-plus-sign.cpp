class Solution {
public:
    void fillDP(vector<vector<int>>& dp, vector<vector<int>>& mat, int n) {
        int down, right, up, left;
        
        for (int i = 0; i < n; i++) {
            down = 0, right = 0;
            
            for (int j = 0; j < n; j++) {
                right = mat[i][j] ? right+1 : 0;
                dp[i][j] = min(dp[i][j], right);
                
                down = mat[j][i] ? down+1 : 0;
                dp[j][i] = min(dp[j][i], down);
            }
        }
        
        for (int i = 0; i < n; i++) {
            up = 0, left = 0;
            for (int j = n-1; j >= 0; j--) {
                left = mat[i][j] ? left+1 : 0;
                dp[i][j] = min(dp[i][j], left);
                
                up = mat[j][i] ? up+1 : 0;
                dp[j][i] = min(dp[j][i], up);
            }
        }
    }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> mat(n, vector<int>(n, 1));
        
        for (auto mine : mines)
            mat[mine[0]][mine[1]] = 0;
        
        fillDP(dp, mat, n);
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};



// class Solution {
// public:
//     int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
//         // vector<vector<int>>mat(n, vector<int>(n, 1));
//         int x = mines.size();
        
//         vector<vector<int>>right(n, vector<int>(n, 1));
//         vector<vector<int>>left(n, vector<int>(n, 1));
//         vector<vector<int>>up(n, vector<int>(n, 1));
//         vector<vector<int>>down(n, vector<int>(n, 1));
//         for(int i=0; i<x; i++){
//             right[mines[i][0]][mines[i][1]] = 0;
//             left[mines[i][0]][mines[i][1]] = 0;
//             up[mines[i][0]][mines[i][1]] = 0;
//             down[mines[i][0]][mines[i][1]] = 0;
//         }
//         for(int i=0; i<n; i++){
//             for(int j=1; j<n; j++){
//                 if(down[j][i] == 0){
//                     continue;
//                 }else{
//                     down[j][i] = down[j][i] + down[j-1][i];
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=n-2; j>=0; j--){
//                 if(up[j][i] == 0){
//                     continue;
//                 }else{
//                     up[j][i] = up[j][i] + up[j+1][i];
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=n-2; j>=0; j--){
//                 if(left[i][j] == 0){
//                     continue;
//                 }else{
//                     left[i][j] = left[i][j] + left[i][j+1];
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=1; j<n; j++){
//                 if(left[i][j] == 0){
//                     continue;
//                 }else{
//                     right[i][j] = right[i][j] + right[i][j-1];
//                 }
//             }
//         }
        
//         int sum = 0;
//         bool flag = true;
//         for(int i=0; i<n; i++){
//             int min_so_far = INT_MAX;
//             for(int j=0; j<n; j++){
//                 if(j-1>=0){
//                     min_so_far = min(min_so_far, right[i][j-1]+1);
//                 }
//                 if(j+1<n){
//                     min_so_far = min(min_so_far, left[i][j+1]+1);
//                 }
//                 if(i-1>=0){
//                     min_so_far = min(min_so_far, up[i-1][j]+1);
//                 }
//                 if(i+1<n){
//                     min_so_far = min(min_so_far, down[i+1][j]+1);
//                 }
//             }
//             sum = max(sum, min_so_far);
//             flag = true;
//         }
//         if(sum == INT_MAX){
//             return 0;
//         }
//         return sum;
//     }
// };




// for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << right[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << left[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << up[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << down[i][j] << ", ";
        //     }
        //     cout << endl;
        // }