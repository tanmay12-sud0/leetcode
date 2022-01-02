class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        int count = 0;
        sort(piles.begin(), piles.end());
        for(int i=n-2; i>=0; i-=2){
            sum += piles[i];
            count++;
            if(count == (n/3)){
                break;
            }
        }
        return sum;
    }
};