class Solution {
public:
    int countElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxa = *max_element(nums.begin(), nums.end());
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == mini){
                cnt1++;
            }
            if(nums[i] == maxa){
                cnt2++;
            }
        }
        if(mini == maxa){
            return 0;
        }
        return nums.size()-cnt1-cnt2;
    }
};