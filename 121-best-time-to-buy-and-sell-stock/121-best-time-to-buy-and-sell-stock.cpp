class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>umap(n, 0);
        umap[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            umap[i] = max(prices[i], umap[i+1]); 
        }
        int max_so_far = INT_MIN;
        for(int i=0; i<n; i++){
            max_so_far = max(max_so_far, umap[i]-prices[i]);
        }
        return max_so_far;
    }
};