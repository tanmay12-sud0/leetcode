class Solution {
public:
    void flipRow(vector<vector<int>>&grid,int m, int x){
        for(int i=0; i<m; i++){
            if(grid[x][i]==1){
                grid[x][i] = 0;
            }else{
                grid[x][i] = 1;
            }
        }
        return;
    }
    void flipCol(vector<vector<int>>&grid, int n, int x){
        for(int i=0; i<n; i++){
            if(grid[i][x]==1){
                grid[i][x] = 0;
            }else{
                grid[i][x] = 1;
            }
        }
        return;
    }
    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
 
    
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            if(grid[i][0]==1){
                continue;
            }
            flipRow(grid,m, i);
        }
        for(int i=0; i<m; i++){
            int zero = 0, one=0;
            for(int j=0; j<n; j++){
                if(grid[j][i]==0){
                    zero++;
                }else{
                    one++;
                }
            }
            if(zero > one){
                flipCol(grid, n, i);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            string s;
            for(int j=0; j<m; j++){
                cout << grid[i][j] << ", ";
                s += to_string(grid[i][j]);
            }
            res += binaryToDecimal(s);
            cout << endl;
        }
        return res;
    }
};