class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& news) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        bool f = true;
        vector<vector<int>>umap;
        for(int i=0; i<n; i++){
            if(intervals[i][1] >= news[0] and news[1] >= intervals[i][0] and f){
                intervals[i][0] = min(intervals[i][0], news[0]);
                intervals[i][1] = max(intervals[i][1], news[1]);
                f = false;
            }
            else{
                if(i != 0 and umap.back()[1] >= intervals[i][0]){
                    umap.back()[1] = max(intervals[i][1], umap.back()[1]);
                    umap.back()[0] = min(intervals[i][0], umap.back()[0]);
                    continue;
                }
            }
            umap.push_back(intervals[i]);
        }
        if(f){
            umap.push_back(news);
            sort(umap.begin(), umap.end());
        }
        return umap;
    }
};
