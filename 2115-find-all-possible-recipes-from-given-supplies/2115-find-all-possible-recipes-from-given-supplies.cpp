class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>>hash;
        map<string, int>umap;
        vector<string>a;
        set<string>sets;
        for(auto x : recipes){
            sets.insert(x);
        }
        for(int i=0; i<recipes.size(); i++){
            for(int j=0; j<ingredients[i].size(); j++){
                hash[ingredients[i][j]].push_back(recipes[i]);
                umap[recipes[i]]++;
            }
        }
       
        queue<string>ss;
        for(auto x : supplies){
            ss.push(x);
        }
        while(!ss.empty()){
            string aa = ss.front();
            ss.pop();
            vector<string>tan = hash[aa];
            for(int i=0; i<tan.size(); i++){
                umap[tan[i]]--;
                if(umap[tan[i]]==0){
                    if(sets.count(tan[i])){
                        a.push_back(tan[i]);
                    }
                    ss.push(tan[i]);
                }
            }
        }
        return a;
    }
};