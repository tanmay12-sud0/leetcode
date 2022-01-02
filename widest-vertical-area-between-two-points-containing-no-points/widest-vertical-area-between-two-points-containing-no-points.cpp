class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int max_so_far = INT_MIN;
        for(int i=0; i<points.size()-1; i++){
            max_so_far = max(max_so_far, points[i+1][0]-points[i][0]);
        }
        return max_so_far;
    }
};