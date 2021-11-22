class Solution {
public:
    string reverseWords(string s) {
        string ss;
        string hash;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                ss += s[i];
            }
            if(!ss.empty() and s[i] == ' '){
                hash = ss +" "+ hash;
                ss.clear();
            }
        }
        hash = ss +" "+ hash;
        hash.pop_back();
        if(hash[0]==' '){
            hash.erase(hash.begin());
        }
        return hash;
    }
};