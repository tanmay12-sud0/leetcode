class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A){
//         int row = matrix.size();
//         int col = matrix[0].size();
       
//         vector<int>hash;
        
//         int start_col = 0;
//         int start_row = 0;
//         int end_row = row-1;
//         int end_col = col-1;
        
//         while(start_row <= end_row and start_col <= end_col){
//             for(int i=start_col; i<=end_col; i++){
//             hash.push_back(matrix[start_row][i]);
//             }
//             start_row++;
            
//                 for(int i=start_row; i<=end_row; i++){
//                  hash.push_back(matrix[i][end_col]);
//                 }
//                 end_col--;
            
        
//             if(start_row < end_row){
//                 for(int i=end_col; i>=start_col; i--){
//                 hash.push_back(matrix[end_row][i]);
//                 }
//                 end_row--;
//             }
//         if(start_col < end_col){
//             for(int i=end_row; i>=start_row; i--){
//                  hash.push_back(matrix[i][start_col]);
//             }
//             start_col++;
//         }
//         }
//         return hash;
        int T,B,L,R,dir;
    T=0;
    B=A.size()-1;
    L=0;
    R=A[0].size()-1;
    dir=0;
    int i;
    vector<int> ans;
    
    while(T<=B && L<=R)
    {
        if(dir==0)
        {
            for(i=L;i<=R;i++)
                ans.push_back(A[T][i]);
            T++;
        }
        else if(dir==1)
        {
            for(i=T;i<=B;i++)
                ans.push_back(A[i][R]);
            R--;
        }
        else if(dir==2)
        {
            for(i=R;i>=L;i--)
                ans.push_back(A[B][i]);
            B--;
        }
        else if(dir==3)
        {
            for(i=B;i>=T;i--)
                ans.push_back(A[i][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    return ans;
        
    }
};