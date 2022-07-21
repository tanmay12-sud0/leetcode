class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int max_so_far = INT_MIN;
        while(left < right){
            max_so_far = max(max_so_far, (right-left)*min(height[left], height[right]));
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_so_far;
    }
};