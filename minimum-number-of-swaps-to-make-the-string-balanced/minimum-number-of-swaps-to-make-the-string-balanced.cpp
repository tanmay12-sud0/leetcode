class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '['){
                st.push(']');
            }else{
                if(!st.empty() and st.top() == ']'){
                    st.pop();
                }else{
                    count++;
                }
            }
        }
        cout << count << endl;
        return (count+1)/2;
    }
};