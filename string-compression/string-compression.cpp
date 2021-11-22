class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 0;
        string s;
        int count =0;
        for(int i=0; i<n; i++){
            if(chars[i] == chars[j]){
                count++;
            }else{
                if(count == 1){
                    s += chars[j];
                    count =0;
                }else{
                    s += chars[j];
                    s += to_string(count);
                    count = 0;
                }
                j = i;
                count++;
            }
        }
        if(count==1){
            s += chars[n-1];
        }else{
            s += chars[n-1];
            s += to_string(count);
        }
        for(int i=0; i<s.length(); i++){
            chars[i] = s[i];
        }
        cout << s << endl;
        return s.length();
    }
};