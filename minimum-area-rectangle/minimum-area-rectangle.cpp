class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_map<int, unordered_set<int>> mymap;
        
        for (auto p : points) {
            mymap[p[0]].insert(p[1]);
        }
        
        /*
            A ----------------------------D
            |(x1, y1)             (x2, y1)|
            |                             |
            |(x1, y2)             (x2, y2)|  
            C ----------------------------B
        */
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int x1 = points[i][0];  // A
                int y1 = points[i][1];  // A
                int x2 = points[j][0];  // B
                int y2 = points[j][1];  //B
                
                if ((x1 != x2) && (y2 != y1)) { // diagonal
                    if (mymap[x1].find(y2) != mymap[x1].end() && mymap[x2].find(y1) != mymap[x2].end()) { // C & D
                        ans = min(ans, (abs(x1-x2) *abs(y1-y2)));
                    }
                }
            }
        }

        return ((ans == INT_MAX) ? 0: ans);
    }
};



// class Solution {
// public:
//     int minAreaRect(vector<vector<int>>& points) {
//         unordered_map<string, int>hash;
//         sort(points.begin(), points.end());
//         int n = points.size();
//         for(int i=0; i<n; i++){
//             string s = to_string(points[i][0])+ " " + to_string(points[i][1]);
//             hash[s]++;
//         }
      
//         bool flag = false;
//         int min_so_far = INT_MAX;
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 int x1 = points[i][0];
//                 int x2 = points[i][1];
//                 int a1 = points[j][0];
//                 int a2 = points[j][1];
//                 if(x1 != a1 and x2 != a2){
//                     string check1 = to_string(x1)+ " " + to_string(a2);
//                 string check2 = to_string(a1)+ " " + to_string(x2);
//                 if(hash[check1] and hash[check2]){
//                     flag = true;
//                     min_so_far = min(min_so_far, (abs(a1-x1)*abs(a2-x2)));
//                 }
//             }
//             }
//         }
//         if(flag)
//             return min_so_far;
//         return 0;
//     }
// };