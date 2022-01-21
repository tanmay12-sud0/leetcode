class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0; i<asteroids.size(); i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            if(st.top()>0 and asteroids[i]<0){
                if(abs(asteroids[i]) < st.top()){
                    continue;
                }
                while(!st.empty() and st.top()>0 and st.top()< abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() and st.top() > 0 and st.top() == abs(asteroids[i])){
                    st.pop();
                    continue;
                }
                if(!st.empty() and abs(asteroids[i]) < st.top()){
                    continue;
                }
                st.push(asteroids[i]);
            }else{
                st.push(asteroids[i]);
            }   
        }
        cout << st.size() << endl;
        vector<int>ss;
        while(!st.empty()){
            ss.insert(ss.begin(), st.top());
            st.pop();
        }
        return ss;
    }
};