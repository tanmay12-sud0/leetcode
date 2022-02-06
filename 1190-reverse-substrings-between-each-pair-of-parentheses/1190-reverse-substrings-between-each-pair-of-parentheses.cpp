class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int n = s.length() ;
        for(int i=0;i<n;i++) {
            if(s[i]==')') {
                string t="";
               while(!st.empty() and st.top() !='('){
                  t+=st.top() ;
                   st.pop() ;
               }
                st.pop() ;
                for(int j=0;j<t.length() ;j++) {
                    st.push(t[j]);
                }
             }
            else
                st. push(s[i]) ;
         }
        string ans="";
        while(!st.empty() and st.top()!='(' ){
              ans = st.top() + ans;
              st.pop() ;
          }
              return ans;
    }
};