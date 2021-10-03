class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>hash1(row, -1);
        vector<int>hash2(col, -1);
        vector<vector<int>>umap;
        
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    hash1[i] = 0;
                    hash2[j] = 0;
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(hash1[i]==0 or hash2[j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
        
    }
};