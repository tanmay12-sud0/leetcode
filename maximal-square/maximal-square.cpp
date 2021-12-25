class Solution {
public:
    bool isSquareWithSide(int side, vector<vector<int>> &pre_matrix) {
	int rows = pre_matrix.size(), cols = pre_matrix[0].size();
        
	for(int i = side; i < rows; ++i) {
		for(int j = side; j < cols; ++j) {
			int cur_area = pre_matrix[i][j] - pre_matrix[i - side][j]
                            - pre_matrix[i][j - side] + pre_matrix[i - side][j - side];
                
			if(cur_area == side * side)
				return true;
		}
	}
	
	return false;
 }
 
int maximalSquare(vector<vector<char>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
        
	vector<vector<int>> pref_matrix(rows + 1, vector<int>(cols + 1, 0));
        
	for(int i = 1; i <= rows; ++i) {
		for(int j = 1; j <= cols; ++j) {
			int tmp = pref_matrix[i][j - 1] + pref_matrix[i - 1][j] - pref_matrix[i - 1][j - 1];

			pref_matrix[i][j] = tmp + (matrix[i - 1][j - 1] == '1');
		}
	}
        
	int low = 0, high = min(rows, cols);
	int max_side = 0;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(isSquareWithSide(mid, pref_matrix))
			low = mid + 1, max_side = mid;
		else
			high = mid - 1;
	}
        
	return max_side * max_side;
}
};