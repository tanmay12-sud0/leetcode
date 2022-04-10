class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(int i=0; i<ops.size(); i++){
            if(ops[i] == "C"){
                s.pop();
            }else if(ops[i] == "D"){
                s.push(2*(s.top()));
            }else if(ops[i] == "+"){
                int x = s.top();
                s.pop();
                int sum = x + s.top();
                s.push(x);
                s.push(sum);
                
            }else{
                int x = stoi(ops[i]);
                s.push(x);
            }
        }
        int add = 0;
        while(!s.empty()){
            add += s.top();
            s.pop();
        }
        return add;
    }
};