class Solution {
public:
//     vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        bool check(vector<int>& nums, int srt, int end)
{
    vector<int> a;
    for(int i=srt;i<=end;i++)
    {
        a.push_back(nums[i]);
    }
    sort(a.begin(),a.end());
    if(a.size()<=1)
        return false;
    int diff = a[1]-a[0];
    for(int j=2;j<a.size();j++)
    {
        if(a[j]-a[j-1]!=diff)
            return false;
    }
    return true;
    
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    
    for(int i=0; i<l.size();i++)
    {
        int srt = l[i];
        int end = r[i];
        if(check(nums , srt,end))
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
// }
        // int n = nums.size();
        // vector<int>umap(n, 0);
        // vector<bool>hash;
        // umap[0] = nums[0];
        // for(int i=1; i<n; i++){
        //     umap[i] = umap[i-1] + nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // int angle = l.size();
        // for(int i=0; i<angle; i++){
        //     if(r[i]-l[i] <=1){
        //         hash.push_back(false);
        //         continue;
        //     }
        //     int prefixSum = l[i]-1>=0 ? umap[r[i]]-umap[l[i]-1] : umap[r[i]];
        //     float new_sum = (float(r[i]-l[i]+1)/2.0)*(2*(nums[l[i]]) + ((r[i]-l[i])*(nums[l[i]+1]-nums[l[i]])));
        //     cout << prefixSum << ", " << new_sum << endl;
        //     if(prefixSum == new_sum){
        //         hash.push_back(true);
        //     }else{
        //         hash.push_back(false);
        //     }
        // }
        // return hash;
    }
};