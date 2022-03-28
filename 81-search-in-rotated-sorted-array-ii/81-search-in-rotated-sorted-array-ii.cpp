class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
            
        }
        nums.clear();
        for(auto x : s){
            nums.push_back(x);
        }
        
        
        int ans = -1;
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[i] <= nums[mid]){
                if(target >= nums[i] and target <= nums[mid]){
                    j = mid-1;
                }else{
                    i = mid + 1;
                }
            }else{
                if(target <= nums[j] and target >= nums[mid]){
                    i = mid  + 1;
                }else{
                    j = mid-1;
                }
            }
        }
        return false;      
    }
};