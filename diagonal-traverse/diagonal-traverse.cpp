class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> umap (row+col-1);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                umap[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>hash;
        bool flag = false;
        int count = 0;
        for(auto x : umap){
            cout << count << endl;
            if(count%2==0){
                    reverse(x.begin(), x.end());
            }
            count++;
            for(auto y : x){
                // cout << (y) << ", ";
                hash.push_back(y);
                
            }
        }
        return hash;
    }
};