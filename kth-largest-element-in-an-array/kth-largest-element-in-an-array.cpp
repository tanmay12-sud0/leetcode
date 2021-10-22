class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>hash;
        for(int i=0; i<nums.size(); i++){
            hash.push(nums[i]);
        }
        for(int i=1; i<k; i++){
            hash.pop();
        }
        return hash.top();
    }
};