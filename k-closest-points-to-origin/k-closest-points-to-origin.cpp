class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // unordered_map<float, int>hash;
        multimap<float, int>pq;
        for(int i=0; i<points.size(); i++){
            float value = (sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])));
            pq.insert({value, i});
            // hash[value] = i;
        }
        int count = 0;
        vector<vector<int>>tan;
        for(auto it = pq.begin(); it != pq.end(); it++){
            tan.push_back(points[it->second]);
            count++;
            if(count == k){
                break;
            }
        }
        // sort(tan.begin(), tan.end());
        return tan;
    }
};