class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(make_pair(s[i], 1));
                continue;
            }
            if(st.top().first == s[i]){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }else{
                st.push(make_pair(s[i], 1));
            }
        }
        s = "";
        while(!st.empty()){
            while(st.top().second>0){
                s += st.top().first;
                st.top().second--;
            }
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};