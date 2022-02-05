class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        string currWord;
        stringstream ss(text);
        map<int, string>hash;
        while(ss >> currWord){
            hash[currWord.length()] += currWord + " ";
        }
        string res;
        for(auto x : hash){
            res += x.second;
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};











// bool compare(const pair<string, int>&a, const pair<string, int>&b){
//     if(a.first.length() == b.first.length()){
//         return a.second < b.second;
//     }
//     return a.first.length()<b.first.length();
// }

// class Solution {
// public:
//     string arrangeWords(string s) {
//         vector<pair<string, int>> hash;
//         char* str = new char[s.length() + 2];
//         strcpy(str, s.c_str());
//         s = "";
//         char strDel[] = " ";
//         int index = 0;
//         char* token = strtok(str, strDel);
//         s += token;
//         s[0] += 32;
//         hash.push_back(make_pair(s, index++));
//         while (token) {
//               token = strtok(NULL, strDel);
//               if(token != NULL){
//                   s += token;
//                   hash.push_back(make_pair(token, index++));
//               }
//         }

//         delete [] str;
//         sort(hash.begin(), hash.end(), compare);
//         s = "";
//         for(auto x : hash){
//             s += x.first;
//             s += " ";
//         }
//         s.erase(s.length()-1, 1);
//         s[0] -= 32;
//         return s;
//     }
// };