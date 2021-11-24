class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_so_far = 0;
        int pre = 0;
        for(int i=0; i<gain.size(); i++){
            pre += gain[i];
            max_so_far = max(max_so_far, pre);
        }
        return max_so_far;
    }
};