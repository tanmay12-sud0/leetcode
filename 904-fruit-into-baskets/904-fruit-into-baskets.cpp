class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>hash;
        int n = fruits.size();
        int count = 0;
        int i = 0, j= 0;
        int max_s_far = INT_MIN;
        while(j<n){
            hash[fruits[j]]++;
            if(hash.size()>2){
                while(hash.size()>2){
                    hash[fruits[i]]--;
                    if(hash[fruits[i]]==0){
                        hash.erase(fruits[i]);
                    }
                    i++;
                }    
            }
            max_s_far = max(max_s_far, j-i+1);
            j++;
        }
        return max_s_far;
    }
};