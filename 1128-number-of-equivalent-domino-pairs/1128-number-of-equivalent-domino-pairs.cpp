class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int>hash;
        int n = dominoes.size();
        int sum = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            string s = to_string(dominoes[i][0]) + to_string(dominoes[i][1]);
            string s2 = to_string(dominoes[i][1]) + to_string(dominoes[i][0]);
            if(hash.count(s)){
                cnt += hash[s];
            }
            if(dominoes[i][0] != dominoes[i][1]){
                if(hash.count(s2)){
                cnt += hash[s2];
                }
            }
            hash[s]++;
        }
        return cnt;
    }
};