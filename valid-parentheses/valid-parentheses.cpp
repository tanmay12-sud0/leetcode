class Solution {
public:
    bool isValid(string s) {
        stack<char>c;
        for(int i=0; s[i]!='\0'; i++){
            if(s[i] == '('){
                c.push(')');
            }else if(s[i] == '{'){
                c.push('}');
            }else if(s[i] == '['){
                c.push(']');
            }
            if(s[i] == ')' or s[i]== '}' or s[i] == ']'){
                if(!c.empty() and c.top() == s[i]){
                    c.pop();
                }else{
                    return false;
                }
            }
        }
        if(c.empty()){
            return true;
        }else{
            return false;
        }
        return true;
    }
};