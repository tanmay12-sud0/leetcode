class Solution {
public:
    vector<int>original;
    vector<int>suffle;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            original.push_back(nums[i]);
            suffle.push_back(nums[i]);
        }
        // reverse(original.begin(), original.end());

    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int len = suffle.size();
        int idx1 = rand()%len;
        int idx2 = rand()%len;
        swap(suffle[idx1], suffle[idx2]);
        return suffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */