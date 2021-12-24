class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a=0,b=0,c=0,d=0;
                if(j-1>=0 and grid[i][j] > grid[i][j-1]){
                    a = abs(grid[i][j] - grid[i][j-1]);
                }
                if(j-1<0){
                    a = grid[i][j];
                }
                
                if(i-1>=0 and grid[i][j] > grid[i-1][j]){
                    b = abs(grid[i][j] - grid[i-1][j]);
                }
                if(i-1<0){
                    b = grid[i][j];
                }
                
                if(j+1<m and grid[i][j] > grid[i][j+1]){
                    c = abs(grid[i][j] - grid[i][j+1]);
                }
                if(j+1>=m){
                    c = grid[i][j];
                }
                
                if(i+1<n and grid[i][j] > grid[i+1][j]){
                    d = abs(grid[i][j] - grid[i+1][j]);
                }
                if(i+1>=n){
                    d = grid[i][j];
                }
                cout << i << "and" << j << ", " << a << b << c << d << endl;
                sum += (a+b+c+d);
            }
        }
        int count =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0){
                    count++;
                }
            }
        }
        return sum + (2*count);
    }
};