class Solution {
public:
    bool checkValidString(string s) {
        stack<int>value;
        stack<int>star;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                value.push(i);
            }
            if(s[i] == ')'){
                if(value.empty() and star.empty()){
                    return false;
                }
                if(!value.empty()){
                    value.pop();
                }else{
                    star.pop();
                }
            }
            if(s[i] == '*'){
                star.push(i);
            }
        }
        while(!value.empty()){
            if(star.empty() or star.top()<value.top()){
                return false;
            }
            value.pop();
            star.pop();
        }
        return true;
    }
};