class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int maxBe = items[0][1];
        vector<int>hash;
        int n = items.size();
        for(int i=1; i<n; i++){
            if(items[i][1] <= maxBe){
                items[i][1] = maxBe;
            }else{
                maxBe = items[i][1];
            }
        }
        map<int, int>umap;
        
        for(auto x : items){
            umap[x[0]] = max(umap[x[0]], x[1]);
        }
        // for(auto xx : umap){
        //     cout << xx.first << " " << xx.second << endl;
        // }
        for(int i=0; i<queries.size(); i++){
            auto xx = umap.upper_bound(queries[i]);
            if(xx == umap.begin()){
                hash.push_back(0);
                continue;
            }
            hash.push_back(prev(xx)->second);
        }
        return hash;
    }
};