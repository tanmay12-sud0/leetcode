class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>hash(numRows);
        for(int i=0; i<numRows; i++){
            hash[i].resize(i+1);
            hash[i][0] = hash[i][i] = 1;
            for(int x=1; x<i; x++){
                hash[i][x] = hash[i-1][x-1] + hash[i-1][x];
            }
        }
        return hash;
    }
};