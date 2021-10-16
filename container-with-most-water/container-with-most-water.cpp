class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int max_so_far=0;
        
        while(left < right){
            int area = min(height[left], height[right])*(right-left);
            max_so_far = max(max_so_far, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_so_far;
    }
};