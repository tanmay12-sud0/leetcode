class Solution {
public:
bool magic(int a,int b,int c,int d,int e,int f,int g,int h,int i){

    set<int>s1={a,b,c,d,e,f,g,h,i};
    set<int>s2={1,2,3,4,5,6,7,8,9};
    
    if(s1==s2 && (a+b+c)==15 && (d+e+f)==15 && (g+h+i)==15 && (a+d+g)==15 && (b+e+h)==15 && (c+f+i)==15 && (a+e+i)==15 && (c+e+g)==15 && e==5 ){
        return true;
    }
    
    return false;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    
    if(m<3 || n<3){
        return 0;
    }
    
    int ans=0;
    for(int i=0;i<m-2;i++){
        for(int j=0;j<n-2;j++){
            
          
            
            if(magic(grid[i][j],grid[i][j+1],grid[i][j+2],grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2])){
                ans+=1;
            }
            
        }
    }
    
    return ans;
    
}
};


// class Solution {
// public:
    
//     bool check(int i, int j, vector<vector<int>>& grid, int n, int m){
//         if(!(i+2<n and j+2<m)){
//             return false;
//         }
//         unordered_set<int>s;
//         unordered_set<int>s1;
//         int sumrow = 0;
//         int sumcol = 0;
//         for(int a=i; a<i+3; a++){
//             for(int b=j; b<j+3; b++){
//                 sumrow += grid[a][b];
//                 sumcol += grid[b][a];
//             }
            
//             s.insert(sumrow);
//             s.insert(sumcol);
//             sumrow = 0;
//             sumcol = 0;
//         }
//         for(int a=i; a<i+3; a++){
//             for(int b=j; b<j+3; b++){
//                 if(grid[a][b]<1 or grid[a][b]>9){
//                     return false;
//                 }
//                 s1.insert(grid[a][b]);
//             }
//         }
//         s.insert(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]);
//         s.insert(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]);
//         cout << s.size() <<", " << i << j <<"" << ", " << s1.size()<< endl;
//         if(s.size() == 1 and s1.size()==9){
//             return true;
//         }
//         return false;
//     }
    
    
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int result = 0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(check(i,j, grid, n, m)){
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };