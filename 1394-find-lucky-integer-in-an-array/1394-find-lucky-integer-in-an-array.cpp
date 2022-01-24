class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>hash;
        for(int i=0; i<arr.size(); i++){
            hash[arr[i]]++;
        }
        int max_so_far = INT_MIN;
        for(auto x : hash){
            if(x.first == x.second){
                max_so_far = max(max_so_far, x.first);
            }
        }
        if(max_so_far == INT_MIN){
            return -1;
        }
        return max_so_far;
    }
};