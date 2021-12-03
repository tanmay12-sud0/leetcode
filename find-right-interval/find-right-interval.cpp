class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int, int>hash;
        vector<int>umap;
        vector<int>ans;
        int n = intervals.size();
        for(int i=0; i<n; i++){
            hash[intervals[i][0]] = i;
            umap.push_back(intervals[i][0]);
        }
        sort(umap.begin(), umap.end());
        for(auto x : umap){
            cout << x << ", ";
        }
        cout << endl;
        for(int i=0; i<n; i++){
            int x = lower_bound(umap.begin(), umap.end(), intervals[i][1])-umap.begin();
            cout << x << endl;
            if(x == n){
                ans.push_back(-1);
            }else{
                ans.push_back(hash[umap[x]]);
            }
        }
        return ans;
    }
};