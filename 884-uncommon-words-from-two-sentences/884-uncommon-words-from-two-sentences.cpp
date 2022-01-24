class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s;
        vector<string>pp;
        s1 += " ";
        s2 += " ";
        unordered_map<string, int>hash;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] == ' '){
                hash[s]++;
                s.clear();
                continue;
            }
            s += s1[i];
        }
        s.clear();
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == ' '){
                hash[s]++;
                s.clear();
                continue;
            }
            s += s2[i];
        }
        for(auto x : hash){
            cout << x.first << ", " << x.second << endl;
            if(x.second == 1){
                pp.push_back(x.first);
            }
        }
        
        return pp;
    }
};