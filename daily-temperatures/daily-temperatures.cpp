class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>s;
        int n = temp.size();
        vector<int>hash(n);
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                hash[i]=0;
                s.push(i);
                continue;
            }
            if(temp[i]<temp[s.top()]){
                hash[i]=s.top()-i;
                s.push(i);
            }else{
                while(!s.empty() and temp[s.top()] <= temp[i]){
                    s.pop();
                }
                if(s.empty()){
                    hash[i]=0;
                }else{
                    hash[i] = s.top()-i;
                }
                s.push(i);
            }
        }
        return hash;
    }
};