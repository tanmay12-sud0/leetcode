bool compare(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        for(auto x : intervals){
            cout << x[0] << " " << x[1] << endl;
        }
        
        for(int i=0; i<intervals.size(); i++){
            while(i+1<intervals.size()){
                if(intervals[i][0] <= intervals[i+1][0] and intervals[i][1] >= intervals[i+1][1]){
                    intervals.erase(intervals.begin() + i+1);
                }else{
                    break;
                }
            }
        }
        return intervals.size();
    }
};