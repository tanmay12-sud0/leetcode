class Solution {
public:
    
    
    
    bool SquareExists(vector<vector<int>>sum,int len,int threshold, int n, int m)
    {
        for(int i=len-1;i<n;i++)
        {
            for(int j=len-1;j<m;j++)
            {
                if(sum[i][j]-(i-len<=0?0:sum[i-len][j])-(j-len<=0?0:sum[i][j-len])+(i-len<=0||j-len<=0?0:sum[i-len][j-len])<=threshold) return true;
            }
        }
        
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=1;j<m; j++){
                mat[i][j] = mat[i][j-1]+mat[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=1;j<n; j++){
                mat[j][i] = mat[j-1][i]+mat[j][i];
            }
        }
        int ans = 0;
        int start = 1;
        int end = min(m, n);
        while(start <= end){
            int mid = (start+end)/2;
            cout << mid << endl;
            if(SquareExists(mat, mid, threshold, n, m)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};