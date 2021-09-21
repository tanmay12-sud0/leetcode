class Solution {
public:
    void validBracket(int n, char *op, int i, int open, int close, vector<string>&s){
    
    if(i == 2*n){
        
        
        op[i] = '\0';
        s.push_back(op);
        return;
    }
    if(open < n){
        op[i] = '(';
        validBracket(n,op, i+1, open+1, close, s);
    }
    if(close < open){
        op[i] = ')';
    validBracket(n, op, i+1, open, close+1,s);
    
    }
}
 
    
    vector<string> generateParenthesis(int n) {
        char op[10000];
        vector<string>s;
        validBracket(n,op, 0, 0, 0, s);
        return s;

    }
};