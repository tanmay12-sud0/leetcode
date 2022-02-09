class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string word;
        int cap = 1;
        while(getline(ss, word, ',')){
            cap--;
            if(cap < 0){
                return false;
            }
            if(word != "#"){
                cap += 2;
            }
        }
        return cap==0;
    }
};


// stack<string>st;
//         preorder += ',';
//         vector<string>hash;
//         string ss;
//         int n = preorder.size();
//         for(int i=0; i<n; i++){
//             if(preorder[i]==','){
//                 hash.push_back(ss);
//                 ss.clear();
//                 continue;
//             }
//             ss += preorder[i];
//         }
//         // for(auto x : hash){
//         //     cout << x << ", ";
//         // }
//         cout << endl;
//         for(auto x : hash){
//             if(x != "#"){
//                 st.push(x);
//             }else{
//                 if(st.empty()){
//                     return false;
//                 }
//                 if(st.top() != "#"){
//                     st.push(x);
//                 }else{
//                     st.pop();
//                     if(!st.empty()){
//                         st.pop();
//                         st.push("#");
//                     }else{
//                         return false;
//                     }
//                 }
//             }
//         }
//         while(!st.empty()){
//             cout << st.top() <<", ";
//             st.pop();
//         }
//         // cout << st.size() << endl;
//         return st.empty();