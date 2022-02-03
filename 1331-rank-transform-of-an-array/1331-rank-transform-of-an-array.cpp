class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int>hash;
        vector<int>umap(arr.size(), 0);
        vector<int>x(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        int cnt = 1;
        for(int i=0; i<arr.size(); i++){
            if(!hash.count(arr[i])){
                hash[arr[i]] = cnt;
                cnt++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            umap[i] = hash[x[i]];
        }
        return umap;
    }
};