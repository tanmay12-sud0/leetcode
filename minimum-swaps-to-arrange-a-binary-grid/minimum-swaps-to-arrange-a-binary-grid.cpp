class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0; i<n; i++) {
            int cnt=0;
            for(int j=grid[i].size()-1; j>=0&&grid[i][j]==0; j--,cnt++);
            grid[i].push_back(cnt);
        }
        int pos=n-1,ans=0;
        for(int i=0; i<n; i++) {
             bool found=false;
             if(grid[i].back()<pos) {
                 for(int r=i+1; r<n; r++) {
                       if(grid[r].back()>=pos) {
                            found=true;
                            for(int k=r; k>i; k--) {
                                 swap(grid[k],grid[k-1]);
                                 ans++;
                            }
                           break;
                       }
                 }
             }else {
                 found=true;
             }
            if(!found) return -1;
            pos--;
        }
        return ans;
    }
};

// class Solution {
// public:
    
//     void swap(int *xp, int *yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }
    
    
//     void bubbleSort(int arr[], int n, int &count)
// {
//    int i, j;
//    bool swapped;
//    for (i = 0; i < n-1; i++)
//    {
//      swapped = false;
//      for (j = 0; j < n-i-1; j++)
//      {
//         if (arr[j] > arr[j+1])
//         {
//             count++;
//            swap(&arr[j], &arr[j+1]);
//            swapped = true;
//         }
//      }
  
//      if (swapped == false)
//         break;
//    }
// }
    
//     int minSwaps(vector<vector<int>>& grid){
        
//         int n = grid.size();
//         int hash[201] = {0};
//         for(int i=0; i<n; i++){
//             int index = -1;
//             for(int j=0; j<n; j++){
//                 if(grid[i][j] == 1){
//                     index = j;
//                 }
//             }
//             hash[i] = index;
//         }
//         int count = 0;
//         bubbleSort(hash, n, count);
//         for(int i=0; i<n; i++){
//             if(hash[i] > i){
//                 return -1;
//             }
//         }

//         for(int i=0; i<n; i++){
//             cout << hash[i] << ", ";
//         }
        
//         return count;
//     }
// };