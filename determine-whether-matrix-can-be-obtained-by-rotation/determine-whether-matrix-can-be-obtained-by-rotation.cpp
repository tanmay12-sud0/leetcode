class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i<j and i!=j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        
        int a = 0,b= col-1;
        while(a<b){
            for(int i=0; i<row; i++){
                swap(matrix[i][a], matrix[i][b]);
            }
            a++,b--;
        }
        return;
    }
    
    bool checkMatrix(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        int m = mat[0].size();
        int a = target.size();
        int b = target[0].size();
        if(n != a or m != b){
            return false;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0; i<4; i++){
            rotate(mat);
            if(checkMatrix(mat, target)){
                return true;
            }
        }
        return false;
    }
};