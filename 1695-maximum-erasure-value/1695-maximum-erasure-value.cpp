class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        int ans = 0, N = A.size(), sum = 0;
        unordered_set<int> s;
        for (int i = 0, j = 0; j < N; ++j) {
            while (s.count(A[j])) {
                s.erase(A[i]);
                sum -= A[i++];
            }
            s.insert(A[j]);
            sum += A[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};