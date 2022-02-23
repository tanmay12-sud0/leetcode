class Solution {
public:
    bool isValid(string s) {
        stack<string>st;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(st.empty()){
                string tt;
                tt += s[i];
                st.push(tt);
            }else{
                if(s[i] == 'a'){
                    string tt;
                    tt += s[i];
                    st.push(tt);
                }else if(s[i] == 'b'){
                    string a = st.top();
                    st.pop();
                    if(a[a.length()-1] == 'a'){
                        a += "b";
                        st.push(a);
                    }else{
                        string tt;
                        tt += s[i];
                        st.push(tt);
                    }
                }else{
                    string a = st.top();
                    st.pop();
                    if(a[a.length()-1] == 'b'){
                        if(a.size()!=2){
                            string tt;
                            tt += s[i];
                            a += tt;
                            st.push(a);
                        }else{
                            continue;    
                        }
                    }else{
                        string tt;
                        tt += s[i];
                        st.push(tt);
                    }
                }
            }
        }
        cout << st.size() << endl;
        return !st.size();
    }
};