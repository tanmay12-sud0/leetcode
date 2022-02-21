bool compare(string &a, string &b){
    return a[a.length()-1] < b[b.length()-1];
}


class Solution {
public:
    string sortSentence(string s) {
        vector<string>sss;
        s += " ";
        string word;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                sss.push_back(word);
                word.clear();
                continue;
            }
            word += s[i];
        }
        sort(sss.begin(), sss.end(), compare);
        string pp;
        for(auto x : sss){
            x = x.substr(0, x.length()-1);
            pp += x;
            pp += " ";
        }
        pp = pp.substr(0, pp.length()-1);
        return pp;
    }
};