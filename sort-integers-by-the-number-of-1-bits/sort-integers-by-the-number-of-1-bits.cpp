class Solution {
public:
    
//     bool compare(int a, int b){
//         int ans1=0,ans2=0;
//         while(a>0){
//             ans1 += (a&1);
//             a = a>>1;
//         }
//         while(b>0){
//             ans2 += (b&1);
//             b = b>>1;
//         }
//         return ans1<ans2;
        
//     }
    
    
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(), arr.end(),[](const int& a, const int& b){
            int countA = __builtin_popcount(a), countB = __builtin_popcount(b);
            return countA==countB ? a<b:countA<countB;});
        return arr;
    }
};