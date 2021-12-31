class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, string>hash;
        vector<string>ss;
        string tan = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]>='a' and s[i] <= 'z'){
                tan += s[i];
            }
            else{
                ss.push_back(tan);
                tan = "";
            }
        }
        if(tan.size()){
            ss.push_back(tan);
        }
        if(ss.size() != pattern.length()){
            return 0;
        }
        
        for(int i=0; i<ss.size(); i++){
            if(hash.count(to_string(pattern[i]))){
                if(hash[to_string(pattern[i])] != ss[i]){
                    return 0;
                }
            }
            if(hash.count(ss[i])){
                if(hash[ss[i]] != to_string(pattern[i])){
                    return 0;
                }
            }
            hash[to_string(pattern[i])] = ss[i];
            hash[ss[i]] = to_string(pattern[i]);
        }
        
        
        for(auto x : ss){
            cout << x << ", ";
        }
        return 1;
    }
};