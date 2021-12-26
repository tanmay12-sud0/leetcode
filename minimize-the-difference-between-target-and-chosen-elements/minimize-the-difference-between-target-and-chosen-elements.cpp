class Solution {
public:

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        bitset<4901>p(1);
    for(auto row: mat){
        bitset<4901>pp;
        for(auto i : row){
            pp |= (p<<i);
        }
        swap(pp, p);
    }
        
        
        int res = INT_MAX;
        for(int i=0; i<4901; i++){
            if(p[i]){
                res = min(res, abs(i-target));
            }
        }
        return res;
    }
};