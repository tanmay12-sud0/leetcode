class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ss;
        int j = 0;
        for(int i=0; i<s.length(); i++){
            if(j<spaces.size() and spaces[j] == i){
                j++;
                ss += " ";
                ss += s[i];
            }else{
                ss += s[i];
            }
            // cout << ss << endl;
        }
        return ss;
    }
};


// int index = 0;
//         for(int i=0; i<spaces.size(); i++){
//             s.insert(spaces[i]+index, " ");
//             index++;
//         }