class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int>hash;
        long long total = 0;
        for(int i=0; i<rectangles.size(); i++){
            if(hash.count(rectangles[i][0]/double(rectangles[i][1]))){
                total += hash[(rectangles[i][0]/double(rectangles[i][1]))];
            }
            hash[(rectangles[i][0]/double(rectangles[i][1]))]++;
        }
        return total;
    }
};