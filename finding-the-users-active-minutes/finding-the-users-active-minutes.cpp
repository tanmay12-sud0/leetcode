class Solution {
public:
    // vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
//         vector<int>umap(k,0);
//         unordered_map<int, int>hash;
//         int len = logs.size();
//         for(int i=0; i<len; i++){
//             if(hash.count(logs[i][0])){
//                 if(hash[logs[i][0]] > logs[i][1]){
//                     hash[logs[i][0]] = logs[i][1];
//                 }
//             }else{
//                 hash[logs[i][0]] = logs[i][1];
//             }
//         }
//         for(auto x : hash){
//             cout << x.first << ", " << x.second << endl;
//             if(x.second.size() <= k){
//                 umap[x.second-1] += 1;
//             }

            
//         }
//         return umap;
        vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>res(k,0);
        map<int,set<int>>m;
        for(vector<int>temp:logs){
            m[temp[0]].insert(temp[1]);
        }
        for(auto it:m){
            if(it.second.size() <= k)
                res[it.second.size()-1]++;
        }
        return res;
    }

    
};