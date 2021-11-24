class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>result;
        int n = nums.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1]+nums[i];
        }
        
        for(int i=0; i<n; i++){
            if(i==0){
                result.push_back(suff[i]-(n-i)*nums[i]);
            }else if(i==n-1){
                result.push_back((i+1)*nums[i]-pre[i]);
            }else{
                result.push_back((suff[i]-(n-i)*nums[i])+((i+1)*nums[i]-pre[i]));
            }
        }
        return result;
    }
};