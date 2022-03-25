bool compare1(vector<int>a, vector<int>b){
    return (a[1] - a[0]) < (b[1] - b[0]);
}

class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), compare1);
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                cout << costs[i][j] <<", ";
            }
            cout << endl;
        }
        int amount = 0;
        for(int i=0; i<n/2; i++){
            vector<int>x = costs.back();
            costs.pop_back();
            amount += x[0];
        }
        for(int i=0; i<costs.size(); i++){
            amount += costs[i][1];
        }
        
        
        return (amount);
    }
};