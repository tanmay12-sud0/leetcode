class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int review = 0;
        unordered_map<int, int>hash;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<wall[i].size(); j++){
                sum += wall[i][j];
                hash[sum]++;
            }
            hash.erase(sum);
            review++;
        }
        int maxa = INT_MIN;
        for(auto x : hash){
            maxa = max(maxa, x.second);
            cout << x.first << ", " << x.second << endl;
        }
        if(maxa == INT_MIN){
            return review;
        }
        return n-maxa;
    }
};