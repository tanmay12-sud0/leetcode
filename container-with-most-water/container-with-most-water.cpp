class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right = height.size()-1;
        int maxs = 0;
        while(left < right){
            maxs = max(maxs, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }else if(height[left] > height[right]){
                right--;
            }else{
                right--;
                left++;
            }
        }
        return maxs;
    }
};