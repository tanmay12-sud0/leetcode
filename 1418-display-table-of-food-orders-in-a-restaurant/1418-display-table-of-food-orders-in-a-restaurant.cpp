class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, vector<string>>hash;
        set<string>ss;
        int n = orders.size();
        for(int i=0; i<n; i++){
            string name = orders[i][0];
            int id = stoi(orders[i][1]);
            string food = orders[i][2];
            hash[id].push_back(food);
            ss.insert(food);
        }
        vector<vector<string>>umap;
        unordered_map<string, int>hash2;
        vector<string>tan;
        tan.push_back("Table");
        int count = 1;
        for(auto x : ss){
            tan.push_back(x);
            hash2[x] = count;
            count++;
        }
        
        umap.push_back(tan);
        tan.clear();
        vector<int>tan1(count, 0);
        for(auto x : hash){
            
            vector<string>nn = x.second;
            tan1[0] = (x.first);
            for(int i=0; i<nn.size(); i++){
                tan1[hash2[nn[i]]]++;
            }
            
            for(int i=0; i<tan1.size(); i++){
                tan.push_back(to_string(tan1[i]));
                tan1[i] = 0;
            }
            umap.push_back(tan);
            tan.clear();
        }
        
        return umap;
    }
};