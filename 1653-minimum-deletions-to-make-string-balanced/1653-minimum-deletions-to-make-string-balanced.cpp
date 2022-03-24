class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n=s.length();
        stack<int>st;
        int count=0;
        for(auto c:s)
        {
            if(st.empty()||c=='b')
                st.push(c);
            else
            {
                if(st.top()=='b')
                { 
                 st.pop();
                 count++;
                }
                else
                    st.push('a');
            }
        }
        return count;
    }
};




// class Solution {
// public:
//     int minimumDeletions(string s) {
//         stack<pair<char, int>>st;
//         int len = s.length();
//         int cnt = 0;
//         int carry = 0;
//         for(int i=0; i<len; i++){
//             if(s[i] == 'a'){
//                 if(st.empty()){
//                     st.push(make_pair('a', 1));
//                 }else if(st.top().first == 'a'){
//                     st.top().second++;
//                 }else{
//                     carry++;
//                     if(st.top().second >= carry){
//                         cnt++;
//                     }else{
//                         st.pop();
//                         st.push({'a', cnt});
//                         carry = 0;
//                     }
//                 }
//             }else{
//                 carry = 0;
//                 if(st.empty()){
//                     st.push({'b',1});    
//                 }else if(st.top().first == 'a'){
//                        st.push({'b', 1});
//                 }else{
//                     st.top().second++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };