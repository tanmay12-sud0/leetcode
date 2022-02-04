class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int res = 0;
        for(int i = 0; i<ages.size();i++){
            int lower = ages[i]*0.5 + 8;
            int cur = upper_bound(ages.begin(),ages.end(),ages[i]) - lower_bound(ages.begin(),ages.end(),lower)-1;
            res += max(cur, 0);
        }
        return res;
    }
};