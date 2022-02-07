class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        int cnt = 0;
        int max_so_far = INT_MIN;
        for(int i=0; i<n; i++){
            st.push(arr[i]);
            max_so_far = max(max_so_far, arr[i]);
            if(i == max_so_far){
                max_so_far = 0;
                cnt++;
                while(!st.empty()){
                    st.pop();
                }
            }
        }
        return cnt;
    }
};