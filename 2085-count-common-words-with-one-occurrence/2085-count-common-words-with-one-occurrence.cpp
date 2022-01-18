class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int>hash1;
        unordered_map<string, int>hash2;
        for(int i=0; i<words1.size(); i++){
            hash1[words1[i]]++;
        }
        int cnt = 0;
        for(int i=0; i<words2.size(); i++){
            hash2[words2[i]]++;
        }
        for(auto x : hash1){
            if(x.second == 1){
                if(hash2.count(x.first) and hash2[x.first]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};