class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int target = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if(len%2==0){
            target = (nums[len/2]+nums[(len/2)-1])/2;
        }else{
            target = (nums[(len/2)]);
        }
       cout << target << endl;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += abs(nums[i]-target);
        }
        return sum;
    }
};