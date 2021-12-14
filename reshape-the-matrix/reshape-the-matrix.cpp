class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if(row*col != r*c){
            return mat;
        }
        vector<int>small;
        vector<vector<int>>big(r, vector<int>(c, 0));
        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                small.push_back(mat[i][j]);
            }
        }
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                big[i][j] = small.back();
                small.pop_back();
            }
        }
        return big;
    }
};