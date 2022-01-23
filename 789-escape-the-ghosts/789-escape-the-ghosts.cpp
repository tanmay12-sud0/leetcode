class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int n = ghosts.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int x = abs(target[0]-ghosts[i][0]);
            int y = abs(target[1]-ghosts[i][1]);
            mini = min(mini, x+y);
        }
        cout << mini << endl;
        int man = abs(target[0])+abs(target[1]);
        return man<mini;
    }
};