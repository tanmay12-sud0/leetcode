class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
         int evencount = 0;
        int oddcount = 0;
    for(auto it = position.begin(); it!= position.end(); it++){
        if(*it%2==0){
            evencount++;
        }else{
            oddcount++;
        }
    }
    return min(evencount, oddcount);
    }
};