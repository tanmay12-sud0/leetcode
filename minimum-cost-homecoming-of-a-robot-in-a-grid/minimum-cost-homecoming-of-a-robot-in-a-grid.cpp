class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int a = startPos[0];
        int b = startPos[1];
        int x = homePos[0];
        int y = homePos[1];
        int sum = 0;
        if(y>=b){
            for(int i=b; i<y; i++){
                sum += colCosts[i+1];
            }
        }
        if(b>=y){
            for(int i=b; i>y; i--){
                sum += colCosts[i-1];
            }
        }
        if(x>=a){
            for(int i=a; i<x; i++){
                sum += rowCosts[i+1];
            }
        }
        if(a>=x){
            for(int i=a; i>x; i--){
                sum += rowCosts[i-1];
            }
        }
        return sum;
    }
};