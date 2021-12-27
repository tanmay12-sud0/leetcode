class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] >= nums[i]){
                ans += nums[i-1]+1-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return ans;
    }
};

// binary search TLE


//      int oper = 0;
//         unordered_set<int>s;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<int>umap;
        
//         for(int i=0; i<n; i++){
//             s.insert(nums[i]);
//         }
        
        
//        for(int i=nums[0]; i<100001; i++){
//            if(!s.count(i)){
//                umap.push_back(i);
//            }
//        } 
      
//         cout << endl;
//         s.clear();
//            for(auto x : umap){
//             cout << x << ", ";
//         }
//         cout << endl;
//         for(int i=0; i<nums.size(); i++){
//             if(!s.count(nums[i])){
//                 s.insert(nums[i]);

//             }else{
//                 int value = nums[i];
//                 cout << "value " << value << endl;
//                 auto it = lower_bound(umap.begin(), umap.end(), value);
//                 umap.erase(it);
//                 cout << *it << endl;
//                 oper += *it-value-1;
//             }
//         }
       
//         return oper;