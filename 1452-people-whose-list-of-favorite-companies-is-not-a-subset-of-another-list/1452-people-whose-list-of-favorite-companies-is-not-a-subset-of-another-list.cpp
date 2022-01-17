class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        const int n = favoriteCompanies.size();
        vector<unordered_set<string> > vecs(n);
        for(int i = 0; i < n; i++)            
            vecs[i].insert(begin(favoriteCompanies[i]), end(favoriteCompanies[i]));
        
        vector<int> ans;
        for(int i = 0,cnt; i < n; i++){                                                            
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(vecs[i].size() > vecs[j].size()) continue; 
                cnt = 0;                            
                for(auto& s: favoriteCompanies[i])                  
                    if( vecs[j].count(s) ) cnt++;                                    
                if(cnt == favoriteCompanies[i].size() ) goto jumpHere;
            }           
            
            ans.push_back(i);
            jumpHere:;            
        }
        return ans;
    }
};