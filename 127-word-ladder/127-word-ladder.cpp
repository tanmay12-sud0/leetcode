class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 0;
        queue<string>q;
        q.push(beginWord);
        q.push("-->");
        set<string>st;
        for(auto x : wordList){
            st.insert(x);
        }
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s == "-->"){
                cnt++;
                if(q.empty()){
                    return 0;
                }
                q.push("-->");
                continue;
            }
            if(s == endWord){
                return ++cnt;
            }
            string ss = s;
            for(int i=0; i<ss.length(); i++){
                for(int j=0; j<26; j++){
                    ss[i] = 'a'+j;
                    if(st.count(ss)){
                        q.push(ss);
                        st.erase(ss);
                    }      
                }
                ss = s;
            }
            
        }
        return 0;
    }
};