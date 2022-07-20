bool compare(int a, int b){
    return abs(a)< abs(b);
}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }
        return nums;
    }
};