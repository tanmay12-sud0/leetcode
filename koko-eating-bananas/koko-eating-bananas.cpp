// class Solution {
// public:
    
//     bool hogya(int mid, vector<int>&piles, int h){
//         int count = 0;
//         for(int i=0; i<piles.size();i++){
//             count += piles[i]/mid; 
//             if(piles[i]%mid)
//                 count++;
//             }
//         cout << count << ", ";
//         if(count > h){
//             return false;
//         }
//         return true;
//     }
    
    
    
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n =piles.size();
       
//         int ans = -1;
//         int start = 0;
//         int end = 1e7;
//         while(start <= end){
//             int mid = (start+end)/2;
//             if(hogya(mid, piles, h)){
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

bool check(int k, int h, vector<int> &piles){
      int count = 0;
      for(auto it : piles){
        count += it / k;
        if(it % k != 0) count++;
      }
      if(count <= h) return true;
      return false;
    }
  
    int minEatingSpeed(vector<int>& piles, int h) {
      int beg = 1, end = INT_MIN, ans;
      for(auto it : piles) if(it > end) end = it;
      
	  while(beg <= end){
        int mid = beg + (end - beg)/2;
        if(check(mid, h, piles)) {
          ans = mid;
          end = mid - 1;
        }
        else beg = mid + 1;
      }
      return ans;
    }
    
};