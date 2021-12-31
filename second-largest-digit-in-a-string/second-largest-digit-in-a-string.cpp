class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        
        for(const char &ch : s) {
            if(isdigit(ch))
                st.insert(ch-'0');
        }
        
        return st.size() > 1 ? *next(rbegin(st)): -1;
    }
};