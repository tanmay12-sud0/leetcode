class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>hash;
        int cnt = 0;
        for(int i=0; i<chars.length(); i++){
            hash[chars[i]]++;
        }
        for(int i=0; i<words.size(); i++){
            string s = words[i];
            unordered_map<char, int>umap;
            bool flag = false;
            for(auto x : s){
                umap[x]++;
                if(!hash.count(x) or hash[x] < umap[x]){
                    flag = true;
                }
            }
            if(!flag){
                cnt += s.length();
            }
        }
        return cnt;
    }
};