class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int>hash;
        string a = "qwertyuiop";
        string b = "asdfghjkl";
        string c = "zxcvbnm";
        for(auto x : a){
            hash[x] = 1;
        }
        for(auto x : b){
            hash[x] = 2;
        }
        for(auto x : c){
            hash[x] = 3;
        }
        vector<string>ss;
        for(int i=0; i<words.size(); i++){
            string xx = words[i];
            set<int>sq;
            for(auto x : xx){
                sq.insert(hash[tolower(x)]);
            }
            if(sq.size()==1){
                ss.push_back(words[i]);
            }
        }
        return ss;
    }
};