class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>ss;
        text += ' ';
        for(auto x : brokenLetters){
            ss.insert(x);
        }
        int cnt = 0;
        bool flag = true;
        for(int i=0; i<text.size(); i++){
            if(text[i] == ' '){
                if(flag){
                    cnt++;
                } 
                flag = true;
            }
            if(ss.count(text[i])){
                flag = false;
            }
        }
        return cnt;
    }
};