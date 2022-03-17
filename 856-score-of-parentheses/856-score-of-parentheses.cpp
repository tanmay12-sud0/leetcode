class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i] == '('){
                st.push(0);
            }else{
                if(st.top() == 0){
                    st.pop();
                    st.push(1);
                }else{
                    int sum = 0;
                    while(st.top() != 0){
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
