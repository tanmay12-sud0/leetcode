class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
        vector<string>s;
        int n = cp.size();
        unordered_map<string, int>hash;
        for(int i=0; i<n; i++){
            string s = cp[i];
            string p;
            string tan;
            for(int i=0; i<s.length(); i++){
                if(s[i]>=0 and s[i]<='9'){
                    p += s[i];
                }else{
                    break;
                }
            }
            for(int i=0; i<s.length(); i++){
                if(s[i] == '.' or s[i]==' '){
                    hash[s.substr(i+1)] += stoi(p);
                }
            }
        }
        for(auto x : hash){
            cout << x.first << ", " << x.second << endl;
            s.push_back(to_string(x.second)+" "+ x.first);
        }
        
        return s;
    }
};