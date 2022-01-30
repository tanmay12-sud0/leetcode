class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        map<int, vector<int>>hash;
        for(int i=0; i<values.size(); i++){
            hash[values[i]].push_back(labels[i]);
        }
        
        int cnt = 0;
        int res = 0;
        map<int, int>umap;
        for(auto it = hash.rbegin(); it != hash.rend(); it++){
            cout << it->first << endl;
            vector<int>x = it->second;
            for(int i=0; i<x.size(); i++){
                if(cnt == numWanted){
                break;
                }
                if(umap.count(x[i]) and umap[x[i]] < useLimit){
                    res += it->first;
                    cout << res << "upper" << endl;
                    umap[x[i]]++;
                    cnt++;
                }
                if(!umap.count(x[i])){
                    res += it->first;
                    cout << res << "lower" << endl;
                    umap[x[i]]++;
                    cnt++;
                }
            }
        }
        
        
        
        
        
        return res;
    }
};




// for(int i=0; i<values.size(); i++){
//             
//         }