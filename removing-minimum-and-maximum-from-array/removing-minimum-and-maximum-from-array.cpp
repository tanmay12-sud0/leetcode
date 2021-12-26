class Solution {
public:
    int minimumDeletions(vector<int>& nums){
        
        int minIndex = -1;
        int maxIndex = -1;
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxIndex = i;
            }
            if(nums[i] < minValue){
                minValue = nums[i];
                minIndex = i;
            }
        }
        
        int op1,op2,op3,op4;
        op1 = max(minIndex+1, maxIndex+1);
        op2 = max(n-minIndex, n-maxIndex);
        op3 = minIndex+1 + (n-maxIndex);
        op4 = maxIndex+1 + (n-minIndex);
        cout << op1 << "," << op2 <<", "<< op3 << ", "<< op4 << endl;
        return min(op1,min(op2,min(op3, op4)));
    }
};