class Solution {
public:
   int kthSmallest(vector<vector<int>>& matrix, int k) {
       int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        for (int i = 0; i < min(row, k); ++i)
            pq.push({matrix[i][0], i, 0});
        //visited[0][0] = true;
       // int count = 0;
        int ans;
         for (int i = 1; i <= k; ++i) {
            auto top = pq.top(); pq.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            if (c + 1 < col) 
                pq.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};