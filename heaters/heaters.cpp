// class Solution {
// public:
    
//     bool hogya(int mid, vector<int> houses, vector<int> heaters){
//         int ans = 0;
//         for (int i = 0; i < houses.size(); ++i) {
//             auto it = lower_bound(heaters.begin(), heaters.end(), houses[i])-heaters.begin();
//             cout << it << endl;
//             if((it<heaters.size() and houses[i]+mid >= heaters[it] ) or (it-1>=0 and houses[i]-mid <= heaters[it-1])){
//                 ans++;
//             }else{
//                 return false;
//             }
//         }
//         return true;
//     }
    
    
//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//         int ans = 0;
//         int sum = 0;
       
//         int len = houses.size();
//         int start = 0;
//         int end = INT_MAX;
//         while(start <= end){
//             int mid = end + (start-end)/2;
//             if(hogya(mid, houses, heaters)){
//                 ans = mid;
//                 end = mid-1;
//             }else{
//                 start = mid+1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
       
       sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int h : houses) {
          auto i = lower_bound(heaters.begin(), heaters.end(), h) - heaters.begin();
          int d = INT_MAX;
            if(i>=1){
                d=min(d,h-heaters[i-1]);
            }
          if (i != heaters.size()) 
              d = min(d, heaters[i]-h);
          ans = max(ans, d);
        }
        return ans;
    }
};