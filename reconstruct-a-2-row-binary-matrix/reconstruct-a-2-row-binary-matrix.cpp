class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<int>rowsum;
        rowsum.push_back(upper);
        rowsum.push_back(lower);
        vector<vector<int>>hash(2, vector<int>(n, 0));
        
        for(int j=0; j<n; j++){
            if(colsum[j]==2){
                    if(rowsum[0]!=0){
                        rowsum[0] -= 1;
                        colsum[j] -= 1;
                        hash[0][j] = 1;
                    }
                    if(rowsum[1]!=0){
                        rowsum[1] -= 1;
                        colsum[j] -=1;
                        hash[1][j] = 1;
                    }
                }
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                if(hash[i][j]==0){
                    int x = min(colsum[j], rowsum[i]);
                    if(x!=0){
                        colsum[j] -= 1;
                        rowsum[i] -= 1;
                        hash[i][j] = 1;
                    }else{
                        hash[i][j] = 0;
                    } 
                } 
            }
        }
//         for(int i=0; i<n; i++){
//             cout << colsum[i] <<", ";
//         }
//         cout << endl;
//         for(int i=0; i<2; i++){
//             cout << rowsum[i] << ", ";
//         }
//         cout << endl;
        

        
        for(int i=0; i<2; i++){
            if(rowsum[i]!=0){
                hash.clear();
                return hash;
            }
        }
        
        for(int i=0; i<n; i++){
            if(colsum[i]!=0){
                hash.clear();
                return hash;
            }
        }
        return hash;
    }
};