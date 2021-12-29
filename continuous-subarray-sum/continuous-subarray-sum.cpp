class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>hash;
        int n = nums.size();
         if(nums.size()<2)
            return false;
        int pre = 0;
        hash[0] = -1;
        for(int i=0; i<n; i++){
            pre += nums[i];
            pre %= k;
            if(hash.count(pre)){
                if(i-hash[pre]>1){
                      return true;
                }
            }else{
                hash[pre] = i;
            }
          
        }
        return false;
    }
};


// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
   
       
//         //Create a hashmap of the running_sum remainder and it's respective index
        
//         unordered_map<int, int> mp;

//         mp[0]=-1;
        
//         int runningSum=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             runningSum+=nums[i];
            
//             if(k!=0) 
//                 runningSum = runningSum%k;
            
//             //check if the runningsum already exists in the hashmap
//             if(mp.find(runningSum)!=mp.end())
//             {
//                 //if it exists, then the current location minus the previous location must be greater than1
                
//                 if(i-mp[runningSum]>1)
//                     return true;
//             }
//             else
//             {
//                 //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                
//                 mp[runningSum]=i;
//             }
                    
//         }
        
//         return false;
        
//     }
// };