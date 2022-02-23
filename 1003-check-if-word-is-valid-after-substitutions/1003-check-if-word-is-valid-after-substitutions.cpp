class Solution {
public:
        bool isValid(string s) {
    vector<char> st;
    for (auto ch : s)
        if (ch == 'c' && st.size() > 1 && st.back() == 'b' && st[st.size() - 2] == 'a')
            st.resize(st.size() - 2);
        else
            st.push_back(ch);
    return st.empty();

    }
};