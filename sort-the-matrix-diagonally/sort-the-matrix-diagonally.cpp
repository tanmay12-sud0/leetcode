class Solution {
public:
    // inplace algorithm
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int k=0; k<n+m; k++){
            for(int i=1; i<n; i++){
                for(int j=1; j<m; j++){
                    if(mat[i-1][j-1] > mat[i][j]){
                        swap(mat[i-1][j-1], mat[i][j]);
                    }
                }
            }
        }
        return mat;
    }
};