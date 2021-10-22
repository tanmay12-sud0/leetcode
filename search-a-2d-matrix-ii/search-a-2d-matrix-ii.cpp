

class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
 int i = 0;
 int j = matrix[0].size() - 1;
 
 while(i < matrix.size() && j >= 0) {
     if(matrix[i][j] == target)
         return true;
     
     if(matrix[i][j] < target)
         i++;
     else
         j--;
 }
 
 return false;
 }
   
};






 // bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size()-1;
//         int i = 0;
//         int j = col-1;
//         while(i< row and j>=0){
//             if(matrix[i][j]==target){
//                 return true;
//             }
//             if(matrix[i][j] > target){
//                 j--;
//             }
//             if(matrix[i][j] < target){
//                 i++;
//             }
//         }
//         return false;