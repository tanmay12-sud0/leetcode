class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0);
        set<char>s1,s2;
        for(char c:word1){
            w1[c-'a']++;
            s1.insert(c);
        }
        for(char c:word2){
            w2[c-'a']++;
            s2.insert(c);
        }
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&s1==s2;
    }
};



// class Solution {
// public:
//     bool closeStrings(string word1, string word2) {
//         unordered_map<char, int>x1;
//         unordered_map<char, int>x2;
//         unordered_map<int, int>x3;
//         unordered_map<char, int>x4;
//         for(auto a : word1){
//             x1[a]++;
//         }
//         for(auto a : word2){
//             x2[a]++;
//         }
//         for(auto a : x1){
//             x4[a.first]++;
//         }
//         for(auto a : x2){
//             x4[a.first]--;
//         }
//         for(auto a : x4){
//             if(a.second != 0){
//                 return false;
//             }
//         }
        
        
//         for(auto a : x1){
//             x3[a.second]++;
//         }
//         for(auto a : x2){
//             x3[a.second]--;
//         }
//         for(auto a : x3){
//             if(a.second != 0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };