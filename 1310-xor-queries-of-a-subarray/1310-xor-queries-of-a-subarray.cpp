class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            arr[i] = arr[i]^arr[i-1];
        }
        vector<int>hash;
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0] == 0){
                 hash.push_back(arr[queries[i][1]]);
            }else{
                hash.push_back(arr[queries[i][1]]^arr[queries[i][0]-1]);
            }
        }
        return hash;
    }
};