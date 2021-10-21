class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hash;
        vector<vector<string>>ss;
        
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            hash[s].push_back(strs[i]);
        }
        for(auto x : hash){
            vector<string>sss;
            for(auto y : x.second){
                sss.push_back(y);
            }
            ss.push_back(sss);
        }
        return ss;
    }
};