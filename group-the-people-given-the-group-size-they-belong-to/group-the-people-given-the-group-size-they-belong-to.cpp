class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>>umap;
        unordered_map<int, vector<int>>hash;
        for(int i=0; i<group.size(); i++){
            hash[group[i]].push_back(i);
        }
        
//         for(auto x : hash){
//             cout << x.first << endl;
//         }
        
        
        for(auto x : hash){
            int size = x.first;
            cout << size << endl;
            vector<int>tan = x.second;
            vector<int>goy;
            for(int i=0; i<tan.size(); i++){
                goy.push_back(tan[i]);
                if(goy.size() == size){
                    umap.push_back(goy);
                    goy.clear();
                }
            }
        }
        return umap;
    }
};