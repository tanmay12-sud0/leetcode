class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int start = 0;
        int end = row;
        vector<int>umap;
        while(start <= end){
            int mid = (start+end)/2;
            int maxa = INT_MIN;
            int value = -1;
            for(int i=0; i<col; i++){
                if(mat[mid][i] > maxa){
                    maxa = mat[mid][i];
                    value = i;
                }
            }
            if(((mid-1>=0 and mat[mid-1][value]<mat[mid][value])  or  mid-1<0) and ((mid+1<row and mat[mid+1][value] < mat[mid][value])  or mid+1>= row)){
                umap.push_back(mid);
                umap.push_back(value);
                return umap;
            }
            if((mid-1>=0 and mat[mid-1][value]>mat[mid][value])){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return umap;
    }
};





// int len = nums.size();
//         if(len == 1){
//             return 0;
//         }
//         if(nums[1] < nums[0]){
//             return 0;
//         }
//         if(nums[len-1] > nums[len-2]){
//             return len-1;
//         }
//         int start = 0;
//         int end = len-1;
//         while(start <= end){
//             int mid = (start+end)/2;
//             if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]){
//                 return mid;
//             }
//             else if(nums[mid+1] > nums[mid]){
//                 start = mid+1;
//             }else{
//                 end = mid-1;
//             }
//         }
//         return -1;