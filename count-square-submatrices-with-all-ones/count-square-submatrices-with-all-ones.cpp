class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

            int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
              
                if(matrix[i][j]>0 and i>0 and j>0){
                    matrix[i][j] = min(matrix[i-1][j], min(matrix[i-1][j-1], matrix[i][j-1]))+1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};