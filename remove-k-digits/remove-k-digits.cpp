class Solution {
public:
        string removeKdigits(string num, int k) {
        if(num.length()==k)return "0";
        // get all eligible elements in a stack
	stack<char> s;
        for(char c:num){
            while(k && !s.empty() && int(s.top())>int(c)){s.pop();k--;} 
            s.push(c);
        } 
        //if still no change in k then remove k elements
        if(k) while(k--){s.pop();}
        // remove leading 0s ,if present
        stack<char> t;
        while(!s.empty()){t.push(s.top());s.pop();}
        while(t.top()=='0'&&t.size()!=1)t.pop();
        //return the answer
        num="";
        while(!t.empty()){num.push_back(t.top());t.pop();}
        return num;
    }
};






// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<char>st;
//         int len = num.length();
//         int count = 0;
//         for(int i=0; i<len; i++){
//             while(!st.empty() and st.top()> num[i] and k>0){
//                 st.pop();
//                 k--;
//             }
//             st.push(num[i]);
//         }
//         string ss;
//         cout << k << endl;
//         while(!st.empty() and k>0){
//             k--;
//             st.pop();
//         }
//         while(!st.empty()){
//             ss = st.top() + ss;
//             st.pop();
//         }
// //         while(k>0){
            
// //         }
//         // string p="";
//         if(ss.length()>1){
//             while(ss.length()>0 and ss[0]=='0'){
//                 ss.erase(ss.begin());
//             }
//             return ss;
//         }
//         // ss += "0";
//         return ss;
//     }
// };