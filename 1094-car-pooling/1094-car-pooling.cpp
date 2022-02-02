bool compare(const vector<int>&a, const vector<int>&b){
    if(a[1]==b[1]){
        return a[2]<b[2];
    }
    return a[1]<b[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(), compare);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0; i<n; i++){
            pq.push(make_pair(trips[i][2], trips[i][0]));
        }
        // capacity -= trips[0][0];
        for(int i=0; i<n; i++){
            capacity -= trips[i][0];
            while(pq.top().first <= trips[i][1]){
                capacity += pq.top().second;
                pq.pop();
            }
            if(capacity < 0){
                return false;
            }
        }
        return true;
    }
};