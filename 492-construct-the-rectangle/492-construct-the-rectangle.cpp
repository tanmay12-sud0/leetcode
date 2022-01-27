class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>hash;
        int x = sqrt(area);
        for(int i=x; i>=1; i++){
            if(area%i==0){
                hash.push_back(max(i, area/i));
                hash.push_back(min(i, area/i));
                break;
            }
        }
        ;
        return hash;
    }
};