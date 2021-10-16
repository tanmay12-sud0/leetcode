class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].length();
         string s;
        for(int i=0; i<len; i++){
           
            for(int x=0; x<strs.size(); x++){
                if(strs[0][i] != strs[x][i]){
                    return s;
                }
            }
            s += strs[0][i];
        }
        return s;
    }
};