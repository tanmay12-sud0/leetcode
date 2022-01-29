class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int m = difficulty.size();
        int max_profit = 0;
        map<int, int>hash;
        hash[0]=0;
        for(int i=0; i<difficulty.size(); i++){
            hash[difficulty[i]] = max(profit[i], hash[difficulty[i]]);
        }
        int mx = 0;
        for(auto &x : hash){
            mx = x.second = max(mx, x.second);
        }
        for(auto x : hash){
            cout << x.first << ", " << x.second << endl;
        }
        for(int i=0; i<n; i++){
            max_profit += prev(hash.upper_bound(worker[i]))->second;
            // cout << max_profit << endl;
        }
        return max_profit;
    }
};