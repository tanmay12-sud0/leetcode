class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>hash(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int minsum = min(rowSum[i], colSum[j]);
                hash[i][j] = minsum;
                rowSum[i] -= minsum;
                colSum[j] -= minsum;
            }
        }
        return hash;
    }
};