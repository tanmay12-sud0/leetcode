class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int n = first.size();
        vector<vector<int>>umap;
        for(int i=0; i<n; i++){
            int a = first[i][0];
            int b = first[i][1];
            for(int j=0; j<second.size(); j++){
                if(a<=second[j][1] and  b>= second[j][0]){
                    int x = max(a, second[j][0]);
                    int y = min(b, second[j][1]);
                    umap.push_back({x, y});
                }
            }
        }
        return umap;
    }
};