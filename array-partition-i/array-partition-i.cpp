class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_so_far = 0;
        int n = nums.size();
        for(int i=n-1; i>=0;){
            int a = nums[i--];
            int b = nums[i--];
            cout << a << b << endl;
            max_so_far += (min(a, b));
        }
        return max_so_far;
    }
};