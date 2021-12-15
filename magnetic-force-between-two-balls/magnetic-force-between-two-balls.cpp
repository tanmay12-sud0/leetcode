class Solution {
public:
    
    // bool hogya(int mid, vector<int>&position, int m, int n){
    //     int count = 1;
    //     int j = 1;
    //     for(int i=0; i<n; i++){
    //         if(position[i]-j>=mid){
    //             count++;
    //             j = position[i];
    //         }
    //     }
    //     cout << "mid " << mid << " " << count << endl;
    //     if(count >= m){
    //         return true;
    //     }
    //     return false;
    // }
    bool hogya(vector<int> positions, int m, int difference) {
        int prev = INT_MIN;
        for(int i = 0; i < positions.size(); i++) 
            if(prev == INT_MIN or positions[i] - prev >= difference) {
                m--;
                prev = positions[i];
            }
        return m <= 0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int start = 1;
        int end = position[n-1]-position[0];
        int ans = 0;
        while(start <= end){
            int mid = (start+end)/2;
            // cout << mid << endl;
            if(hogya(position, m, mid)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
         return ans;
    }
};