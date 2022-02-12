class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int len = indices.size();
        vector<int>verticle(m, 0);
        vector<int>hori(n, 0);
        for(int i=0; i<len; i++){
            int x = indices[i][0];
            int y = indices[i][1];
            hori[y]++;
            verticle[x]++;
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((hori[j]+verticle[i])%2!=0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};