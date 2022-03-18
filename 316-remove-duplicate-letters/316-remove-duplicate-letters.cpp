class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        int len = s.length();
        vector<bool>InTheStack(26, 0);
        vector<int>LastIndex(26, 0);
        for(int i=0; i<len; i++){
            LastIndex[s[i]-'a'] = i;
        }
        for(int i=0; i<len; i++){
            if(!InTheStack[s[i]-'a']){
                
                while(!st.empty() and st.top()>s[i] and LastIndex[st.top()-'a']>i){
                    InTheStack[st.top()-'a'] = false;
                    st.pop();
                }
                
                st.push(s[i]);
                InTheStack[s[i]-'a'] = true;
            }
        }
        string ss;
        while(!st.empty()){
            ss = st.top() + ss;
            st.pop();
        }
        return ss;
    }
};