class Solution {
public:
    
    bool isValid(vector<int> nums,int n, int m, int mid){
        int assn=1; //assignments=1 initially , means can we allocate the values to 1 partition only without violating the condition of having sum <=mid;
        int sum=0;
        for(int i : nums){
            sum+=i;
            if (sum>mid){
                assn++;
                sum=i;
                if (sum>mid) //if at any instance we find that this value is greater than current max sum we are checking for we return false;
                    return false;
            }
            if (assn>m) //if we need more than required partitions for the current max ("mid") value we are checking for we return false;
                return false;
        }
        return true; // if everything is fine without violating any condition we return true;
    }

    
    
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int n = nums.size();
        for(auto x : nums){
            sum += x;
        }
        int left = 0;
        int ans = -1;
        int right = sum;
        while(left <= right){
            int mid = (left + right)/2;
            if(isValid(nums,n, m, mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};