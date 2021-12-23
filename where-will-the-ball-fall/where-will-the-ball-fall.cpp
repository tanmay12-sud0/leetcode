class Solution {
public:
    vector<int>umap;
    void dfs(int i, int j, int n, int m,vector<vector<int>>&grid, bool &flag, int &value){
            
            if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1 and j+1<m and grid[i][j+1]!= -1){    
                if(i+1 >= n){
                    value = j+1;
                    flag = true;
                    return;
                }
                dfs(i+1, j+1, n, m, grid, flag, value);
            }
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==-1 and j-1>=0 and grid[i][j-1]!= 1){    
                if(i+1 >= n){
                    value = j-1;
                    flag = true;
                    return;
                }
                dfs(i+1, j-1, n, m, grid, flag, value);
            }
        return;
    }
    

    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<m; i++){
            bool flag = false;
            int value = -1;
            dfs(0, i, n, m, grid, flag, value);
            if(flag){
                umap.push_back(value);
            }else{
                umap.push_back(-1);
            }
        }
        return umap;
    }
};