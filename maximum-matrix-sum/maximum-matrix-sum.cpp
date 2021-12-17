class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         int n = matrix.size();
         int m = matrix[0].size();
         int start = INT_MAX;
         int cnt = 0;
        long long int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    cnt++;
                }
                start = min(start, abs(matrix[i][j]));
            }
        }
        cout << start << endl;
        if(cnt%2==0){
            return sum;
        }else{
            return sum-2*start;
        }
        return 0;
    }
};