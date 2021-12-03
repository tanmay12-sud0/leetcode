class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int start = 0, len = citations.size(), end = len - 1;
        while (start <= end) {
            int mid = (start + end)/2;
            if (citations[mid] < len - mid)
                start = mid + 1;
            else if (citations[mid] > len - mid)
                end = mid - 1;
            else return len - mid;
        }
        return len - start;
    }
};



// class Solution {
// public:
    
//     bool hosaktahai(vector<int>&c, int mid, int n){
//         cout << "Hello" << endl;
//         int diff = n-mid;
//         if(diff >= c[mid]){
//             return true;
//         }
//        return false;
//     }
    
    
//     int hIndex(vector<int>& c) {
//         int n = c.size();
//         int start = 0;
//         int end = n-1;
//         int ans = -1;
//         while(start <= end){
//             int mid = end + (start - end)/2;
//             if(mid < 0 or mid >= n){
//                 return -1;
//             }
//             if(hosaktahai(c, mid, n)){
//                 ans = mid;
//                 start  = mid+1;
//             }else{
//                 end = mid-1;
//             }
//         }
//         return c[ans];
//     }
// };