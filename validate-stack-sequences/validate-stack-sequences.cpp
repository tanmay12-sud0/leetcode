class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int j=0;
        for(int i=0; i<pushed.size();){
            if(!s.empty() and popped[j] == s.top()){
                j++;
                s.pop();
            }else{
                s.push(pushed[i]);
                i++;
            }
            
        }
        cout << j << endl;
        cout << s.top() << endl;
        while(!s.empty() and s.top() == popped[j]){
            s.pop();
            cout << "hello" << ",";
            j++;
        }
        if(s.empty() and j == popped.size()){
            return true;
        }
        while(!s.empty()){
            cout << s.top() <<", ";
            s.pop();
        }
        return false;
    }
};