class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row = n;
        int col = n;
       
        // vector<int>hash;
        vector<vector<int>>matrix(n, vector<int> (n, 0));
        int start_col = 0;
        int start_row = 0;
        int end_row = row-1;
        int end_col = col-1;
        int count = 1;
        while(start_row <= end_row and start_col <= end_col){
            for(int i=start_col; i<=end_col; i++){
            
                matrix[start_row][i] = count++;
            }
            start_row++;
            
                for(int i=start_row; i<=end_row; i++){
                 
                    matrix[i][end_col] = count++;
                }
                end_col--;
            
        
            if(start_row <= end_row){
                for(int i=end_col; i>=start_col; i--){
                
                    matrix[end_row][i] = count++;
                }
                end_row--;
            }
        if(start_col <= end_col){
            for(int i=end_row; i>=start_row; i--){
                 
                matrix[i][start_col] = count++;
            }
            start_col++;
        }
        }
        return matrix;
    }
};





