class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        for(int i = 0, j = 0; i < A.size() && j < B.size();) {
	        int lo = max(A[i][0], B[j][0]), hi = min(A[i][1], B[j][1]);
	        if(lo <= hi) res.push_back({lo, hi});
	        if(hi == A[i][1]) i++;
	        else j++;
        }
        return res;
    }
};


// int n = first.size();
        // vector<vector<int>>umap;
        // for(int i=0; i<n; i++){
        //     int a = first[i][0];
        //     int b = first[i][1];
        //     for(int j=0; j<second.size(); j++){
        //         if(a<=second[j][1] and  b>= second[j][0]){
        //             int x = max(a, second[j][0]);
        //             int y = min(b, second[j][1]);
        //             umap.push_back({x, y});
        //         }
        //     }
        // }
        // return umap;