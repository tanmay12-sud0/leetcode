class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m =box[0].size();
        // vector<vector<char>>hash(m, vector<char>(n, '.'));
        for(int i=0; i<n; i++){
            int z = m-1;
            for(int j=m-1; j>=0; j--){
                if(box[i][j]=='.'){
                    continue;
                }
                if(box[i][j]=='*'){
                    z = j-1;
                }
                if(box[i][j] == '#'){
                    if(z == j){
                        z--;
                        continue;
                    }
                    box[i][z] = '#';
                    box[i][j] = '.';
                    // swap(box[j], box[z]);
                    z--;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << box[i][j] << ", ";
            }
            cout << endl;
        }
         vector<vector<char>> ans(box[0].size(), vector<char>(box.size()));
        
        for(int j=0; j<box[0].size(); j++)
        {
            for(int i=0; i<box.size(); i++)
               ans[j][i] = box[i][j];
        }
        
        for(auto &it:ans)
            reverse(begin(it), end(it));
        
        return ans;
    }
};