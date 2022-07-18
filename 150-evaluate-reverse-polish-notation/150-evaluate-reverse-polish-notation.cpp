class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>hash;
        int len = tokens.size();
        for(int i=0; i<len; i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                int x = hash.top();
                hash.pop();
                int y = hash.top();
                hash.pop();
                if(tokens[i] == "+"){
                    int sum = x+y;
                    hash.push(sum);
                }else if(tokens[i] == "-"){
                    int diff = y-x;
                    hash.push(diff);
                }else if(tokens[i] == "*"){
                    int mul = x*y;
                    hash.push(mul);
                }else{
                    int div = y/x;
                    hash.push(div);
                }
            }else{
                hash.push(stoi(tokens[i]));
            }
        }
        return hash.top();
    }
};