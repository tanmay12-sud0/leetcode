class Solution {
public:
    string makeGood(string s) {
        int len = s.length();
        stack<char>st;
        for(int i=0; i<len; i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top() + 32 == s[i] or st.top()-32==s[i]){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        string p;
        while(!st.empty()){
            p = st.top() + p;
            st.pop();
        }
        return p;
    }
};