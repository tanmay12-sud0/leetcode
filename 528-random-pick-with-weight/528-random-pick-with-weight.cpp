class Solution {
public:
    int c_sum = 0;
    vector<int>hash;
    Solution(vector<int>& w) {
        for(int i=0; i<w.size(); i++){
            c_sum += w[i];
            hash.push_back(c_sum);
        }
    }
    
    int pickIndex() {
        int value = rand()%c_sum;
        auto it = upper_bound(hash.begin(), hash.end(), value)- hash.begin();
        return it;
    }
};
