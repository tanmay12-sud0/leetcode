class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int>hash;
        int n = points.size();
        if(n<3){
            return 0;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                if(hash.count(dist)){
                    count += hash[dist]; 
                }
                hash[dist]++;
            }
            cnt += 2*count;
            hash.clear();
        }
        return cnt;
    }
};