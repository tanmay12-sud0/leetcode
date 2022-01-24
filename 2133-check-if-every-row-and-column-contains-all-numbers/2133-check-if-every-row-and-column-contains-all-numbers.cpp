class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        set<int>ss;
        for(int i=0; i<n; i++){
            int maxa = INT_MIN;
            for(int j=0; j<n; j++){
                ss.insert(matrix[i][j]);
                maxa = max(maxa, matrix[i][j]);
            }
            if(ss.size()!= n or maxa > n){
                return false;
            }
            ss.clear();
        }
        for(int i=0; i<n; i++){
            int maxa = INT_MIN;
            for(int j=0; j<n; j++){
                ss.insert(matrix[j][i]);
                maxa = max(maxa, matrix[j][i]);
            }
            if(ss.size()!= n or maxa > n){
                return false;
            }
            ss.clear();
        }
        return true;
    }
};