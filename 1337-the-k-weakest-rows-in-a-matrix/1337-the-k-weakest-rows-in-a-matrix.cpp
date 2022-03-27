class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>umap;
        for(int i=0; i<mat.size(); i++){
            int counter =0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 1){
                    counter++;
                } 
            }
             umap.push_back(counter);
        }
        
        vector<int>tan;
        for(int i=0; i<k; i++){
            int min=10000;
          
            int x=0;
            for(int j=0; j<umap.size(); j++){
                if(umap[j]<min){
                    min = umap[j];
                    x = j;
                }
            }
            umap[x] = 1000;
            tan.push_back(x);
        }
        return tan;
    }
};