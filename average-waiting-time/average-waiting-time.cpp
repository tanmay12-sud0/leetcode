class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int len = customers.size();
        int time = 0;
        double ans = customers[0][1];
        cout << ans << ", ";
        time = customers[0][0]+customers[0][1];
        for(int i=1; i<len; i++){
            if(time >= customers[i][0]){
                time += customers[i][1];
                ans += (time - customers[i][0]);
                cout << ans << ", ";
            }else{
                // cout << "hello";
                time = customers[i][0]+customers[i][1];
                ans += customers[i][1];
                cout << ans << ", ";
            }
        }
        return ans/len;
    }
};