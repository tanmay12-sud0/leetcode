class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ss;
        string word;
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(count == k){
                ss.push_back(word);
                word.clear();
                count = 0;
            }
            word += s[i];
            count++;
        }
        while(word.length() < k){
            word += fill;
        }
        ss.push_back(word);
        return ss;
    }
};