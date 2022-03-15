class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>>hash;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                hash.push(make_pair('(', i));
            }
            if(s[i] == ')'){
                if(!hash.empty() and hash.top().first == '('){
                    hash.pop();
                }else{
                    hash.push(make_pair(')', i));
                }
            }
        }
        while(!hash.empty()){
            s.erase(s.begin() + hash.top().second);
            hash.pop();
        }
        return s;
    }
};