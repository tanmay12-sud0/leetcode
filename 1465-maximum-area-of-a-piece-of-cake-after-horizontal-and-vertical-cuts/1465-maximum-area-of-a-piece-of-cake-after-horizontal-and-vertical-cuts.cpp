const int MOD = 1e9 + 7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long int ans = 0, maxWidth = 0, maxHeight = 0;
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        
        for (int i = 0, prev = 0; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight, (long int) horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        
        for (int i = 0, prev = 0; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth, (long int) verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        
        return (maxWidth * maxHeight) % MOD;
    }
};






// class Solution {
// public:
//     const int MOD = 1e9 + 7
//     int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
//         sort(horizontalCuts.begin(), horizontalCuts.end());
//         sort(verticalCuts.begin(), verticalCuts.end());
//         long int hori = horizontalCuts[0] - 0;
//         long int ver = verticalCuts[0] - 0;
        
//         for(int i=1; i<verticalCuts.size(); i++){
//             ver = max(ver, (long int)verticalCuts[i] - verticalCuts[i-1]);
//         }
//         ver = max(ver, w - verticalCuts[verticalCuts.size()-1]);
        
//         for(int i=1; i<horizontalCuts.size(); i++){
//             hori = max(hori, horizontalCuts[i] - horizontalCuts[i-1]);
//         }
//         hori = max(hori, h - horizontalCuts[horizontalCuts.size()-1]);
//         cout << hori << " , " << ver << endl;
//         return (((hori)%100000007 )* ((ver)%100000007))%100000007;
//     }
// };