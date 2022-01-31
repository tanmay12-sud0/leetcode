class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, buy, sell, profit = 0, N = prices.size() - 1;
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) i++;
            buy = prices[i];

            while (i < N && prices[i + 1] > prices[i]) i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
        // int amount = 0;
        // int buy = -1;
        // int sell = -1;
        // int n = prices.size();
        // if(prices.size()==1){
        //     return 0;
        // }
        // for(int i=0; i<n; i++){
        //     if(prices[i] < prices[i+1] and i==0 and sell == -1){
        //         buy = prices[i];
        //         continue;
        //     }
        //     if(i!=0 and i!=n-1 and prices[i]<prices[i+1] and prices[i]<prices[i-1] and sell == -1 and buy == -1){
        //         buy = prices[i];
        //         continue;
        //     }
        //     if(i!=n-1 and i!=0 and prices[i]>prices[i+1] and prices[i]>prices[i-1] and buy != -1 and sell == -1){
        //         sell = prices[i];
        //         amount += (sell-buy);
        //         buy = -1;
        //         sell = -1;
        //         continue;
        //     }
        //     if(i==n-1 and buy != -1 and prices[i-1]<prices[i]){
        //         sell = prices[i];
        //         amount += (sell-buy);
        //         buy = -1;
        //         sell = -1;
        //         continue;
        //     }
        // }
        // return amount;
    }
};