class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy=0, yx=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]=='x' && s2[i]=='y') xy++;
            else if(s1[i]=='y' && s2[i]=='x') yx++;
        }
        if(xy%2 != yx%2) return -1;
        return xy/2 + yx/2 + (xy%2) * 2;
    }
};

// class Solution {
// public:
//     int minimumSwap(string s1, string s2) {
//         int len = s1.length();
//         int res = 0;
//         int countX = 0;
//         int countY = 0;
//         for(int i=0; i<len; i++){
//             if(s1[i]=='x'){
//                 countX++;
//             }
//             if(s1[i]=='y'){
//                 countY++;
//             }
//             if(s2[i]=='x'){
//                 countX++;
//             }
//             if(s2[i]=='y'){
//                 countY++;
//             }
//         }
//         cout << countX <<", " << countY << endl;
//         if(countX%2!=0 or countY%2!=0){
//             return -1;
//         }
//         for(int i=1; i<len; i++){
//             if(s1[i-1]=='x' and s1[i]=='x' and s2[i-1]=='y' and s2[i]=='y'){
//                 res += 1;
//                 swap(s1[i-1], s2[i]);
//             }
//         }
//         for(int i=1; i<len; i++){
//             if(s1[i-1]=='x' and s1[i]=='y' and s2[i-1]=='y' and s2[i]=='x'){
//                 res += 2;
//                 swap(s1[i-1], s2[i-1]);
//             }
//         }
//         cout << s1 << endl;
//         cout << s2 << endl;
//         return res;
//     }
// };