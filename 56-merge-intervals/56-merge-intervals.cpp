class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size();
        if(n<=1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>hash;
        hash.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[i][0] > hash.back()[1]){
                hash.push_back(intervals[i]);
            }else{
                hash.back()[1] = max(hash.back()[1], intervals[i][1]);
            }
        }
        return hash;
    }
};