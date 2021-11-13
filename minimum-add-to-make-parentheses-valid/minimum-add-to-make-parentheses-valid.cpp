class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>hash;
        for(auto x : s){
            // cout << x << ", ";
            if(x == '('){
                hash.push(')');
            }
            if(x == ')'){
                if(!hash.empty() and hash.top()==')'){
                    
                    hash.pop();
                }else{
                    hash.push('(');
                }
            }
        }
        return hash.size();
    }
};