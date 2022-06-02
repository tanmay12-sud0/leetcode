class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        long long int i,j;
        vector<vector<int> > transpose( matrix[0].size(), vector<int> (matrix.size(), 0));
        for( i=0; i<matrix.size(); i++){
            for( j=0; j<matrix[0].size(); j++)
                    transpose[j][i] = matrix[i][j];
                
        }
        return transpose;
    }
};
