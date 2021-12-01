class Solution {
public:
        
        string counts(string s){
                string p;
                int len = s.length();
                int count = 1;
                for(int i=0; i<len; i++){
                        if(s[i]==s[i+1]){
                                count++;
                                continue;
                        }else{
                                p += to_string(count);
                                p += s[i];
                                count = 1;
                        }
                }
                return p;
        }
        
        
        
    string countAndSay(int n) {
        string s = "1";
            if(n==1){
                    return s;
            }
            for(int i=2; i<=n; i++){
                   s = counts(s);
                    cout << s << endl;
            }
            return s;
    }
};