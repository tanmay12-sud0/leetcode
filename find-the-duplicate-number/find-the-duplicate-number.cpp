class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int fast = nums[0];
        int slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        fast = nums[0];
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
        
        
    }
    
};


// time == bego(nlogn) solution  
// space == bego(1) solution

// sort(nums.begin(), nums.end());
//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i] == nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return 0;


// time -- bego(n)
// space == bego(n)

//  vector<int> umap(nums.size()+1,0);
//         for(int i=0; i<nums.size(); i++){
//             umap[nums[i]]++;
//         }
        
//         for(int i=0; i<umap.size(); i++){
//             if(umap[i] > 1){
//                 return i;
//             }
//         }
//         return 0;