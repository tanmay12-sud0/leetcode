class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){

             int row = matrix.size();
        int col = matrix[0].size();
       
        vector<int>hash;
        
        int start_col = 0;
        int start_row = 0;
        int end_row = row-1;
        int end_col = col-1;
        
        while(start_row <= end_row and start_col <= end_col){
            for(int i=start_col; i<=end_col; i++){
            hash.push_back(matrix[start_row][i]);
            }
            start_row++;
            
                for(int i=start_row; i<=end_row; i++){
                 hash.push_back(matrix[i][end_col]);
                }
                end_col--;
            
        
            if(start_row <= end_row){
                for(int i=end_col; i>=start_col; i--){
                hash.push_back(matrix[end_row][i]);
                }
                end_row--;
            }
        if(start_col <= end_col){
            for(int i=end_row; i>=start_row; i--){
                 hash.push_back(matrix[i][start_col]);
            }
            start_col++;
        }
        }
        return hash;
        
    }
};



