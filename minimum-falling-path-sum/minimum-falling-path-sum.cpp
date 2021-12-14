class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>hash(n, vector<int>(m, INT_MAX));
        for(int i=0; i<m; i++){
            hash[0][i] = matrix[0][i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                    if(i+1>=0 and j-1>=0 and i+1<n and j-1<m){
                        hash[i+1][j-1] = min(hash[i+1][j-1], hash[i][j]+matrix[i+1][j-1]);
                    }
                    if(i+1>=0 and j>=0 and i+1<n and j<m){
                        hash[i+1][j] = min(hash[i+1][j], hash[i][j]+matrix[i+1][j]);
                    }
                    if(i+1>=0 and j+1>=0 and i+1<n and j+1<m){
                        hash[i+1][j+1] = min(hash[i+1][j+1], hash[i][j]+matrix[i+1][j+1]);
                    }
                } 
        }
        int min_ans = INT_MAX;
            for(int j=0; j<m; j++){
                // cout << hash[i][j] << ", ";
                min_ans = min(min_ans, hash[n-1][j]);
            }
        
        return min_ans;
    }
};