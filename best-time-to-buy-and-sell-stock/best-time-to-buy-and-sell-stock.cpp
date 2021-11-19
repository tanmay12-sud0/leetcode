class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>umap(prices.begin(), prices.end());
        for(int i = n-2; i>=0; i--){
            umap[i] = max(umap[i], umap[i+1]);
        }
        int sum_so_far = 0;
        
        for(int i=0; i<n; i++){
            if(umap[i] > prices[i]){
                sum_so_far = max(sum_so_far, (umap[i]-prices[i]));
            }
        }
        return sum_so_far;
    }
};