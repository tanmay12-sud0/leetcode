class DetectSquares { 
public:
    int cntPoints[1001][1001] = {};
    vector<pair<int, int>> points;

    void add(vector<int> p) {
        cntPoints[p[0]][p[1]]++;
        points.emplace_back(p[0], p[1]);
    }

    int count(vector<int> p1) {
        int x1 = p1[0], y1 = p1[1], ans = 0;
        for (auto& [x3, y3] : points) {
            if (abs(x1-x3) == 0 || abs(x1-x3) != abs(y1-y3))
                continue;
            ans += cntPoints[x1][y3] * cntPoints[x3][y1];
        }
        return ans;
    }
};


// class DetectSquares {
// public:
//     set<pair<int, int>>globals;
//     unordered_map<int, vector<vector<int>>>hashX;
//     unordered_map<int, vector<vector<int>>>hashY;
    
//     DetectSquares() {
        
//     }
    
//     void add(vector<int> point) {
//         int x = point[0];
//         int y = point[1];
//         globals.insert(make_pair(x, y));
//         hashX[x].push_back({x, y});
//         hashY[y].push_back({x, y});
//         return;
//     }
    
//     int count(vector<int> point) {
//         int cnt = 0;
//         int x = point[0];
//         int y = point[1];
//         // if(!hashX.count(x) or !hashY.count(y)){
//         //     return  cnt;
//         // }
//         if(hashX.count(x) and hashY.count(y)){
//             vector<vector<int>>a = hashX[x];
//             vector<vector<int>>b = hashY[y];
//             for(int i=0; i<a.size(); i++){
//                 for(int j=0; j<b.size(); j++){
//                     int x1 = a[i][0];
//                     int y1 = a[i][1];
//                     int x2 = b[j][0];
//                     int y2 = b[j][1];
//                     if(globals.count(make_pair(x2, y1)) or globals.count(make_pair(x1, y2))){
//                         cnt++;
//                     }
//                 }
//             }
//         }
//         return cnt;
//     }
// };
