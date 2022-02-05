bool compare(const pair<string, int>&a, const pair<string, int>&b){
    if(a.first.length() == b.first.length()){
        return a.second < b.second;
    }
    return a.first.length()<b.first.length();
}

class Solution {
public:
    string arrangeWords(string s) {
        vector<pair<string, int>> hash;
        char* str = new char[s.length() + 2];
        strcpy(str, s.c_str());
        s = "";
        char strDel[] = " ";
        int index = 0;
        char* token = strtok(str, strDel);
        s += token;
        s[0] += 32;
        hash.push_back(make_pair(s, index++));
        while (token) {
              token = strtok(NULL, strDel);
              if(token != NULL){
                  s += token;
                  hash.push_back(make_pair(token, index++));
              }
        }

        delete [] str;
        sort(hash.begin(), hash.end(), compare);
        s = "";
        for(auto x : hash){
            s += x.first;
            s += " ";
        }
        s.erase(s.length()-1, 1);
        s[0] -= 32;
        return s;
    }
};