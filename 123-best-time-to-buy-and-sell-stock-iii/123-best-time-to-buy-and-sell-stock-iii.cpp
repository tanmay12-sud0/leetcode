class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<int>left(n);
        vector<int>right(n);                                                                                           
        int lmin=prices[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],prices[i]-lmin);
            lmin=min(lmin,prices[i]);
        }
        int rmin=prices[n-1];
         for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],rmin-prices[i]);
            rmin=max(rmin,prices[i]);
        }
          int profit = right[0];
        for(int i=1;i<n;++i)
            profit = max(profit,left[i-1]+right[i]);
        
        return profit;
    }
};