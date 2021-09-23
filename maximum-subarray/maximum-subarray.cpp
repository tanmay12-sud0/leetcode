class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs =0;
        int ms =INT_MIN;
       
        
        for(int i=0; i<nums.size(); i++){
            cs += nums[i];
            ms = max(ms, cs);
            if(cs < 0){
                cs =0;
            }
            
        }
        return ms;
    }
};


//   int maxs=0;
//         int sum =0,tan=0,counter=0;
//         for(int i=0; i<nums.size(); i++){
//             tan += nums[i];
//             if(nums[i] < 0){
//                 counter++;
//             }
//         }
//         for(int i=0; i<nums.size(); i++){
//              sum += nums[i];
//             if(sum >= 0){
               
//                 maxs = max(sum, maxs);
//             }else{
//                 sum = 0;
//             }
//         }
//         if(counter == nums.size()){
//             return tan;
//         }
//         return maxs;