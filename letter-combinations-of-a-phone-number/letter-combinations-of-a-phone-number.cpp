class Solution {
public:
    vector<string>ss = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>hash;
    void findRecursion(string digits, char *out, int i, int j){
        if(digits[i] == '\0'){
            out[j] == '\0';
            hash.push_back(out);
            return;
        }
        int digit = digits[i]-'0';
        for(int k=0; ss[digit][k]!='\0'; k++){
            out[j] = ss[digit][k];
            findRecursion(digits, out, i+1, j+1);
            
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        char out[100]= "";
        if(digits.length() == 0){
            return hash;
        }
        findRecursion(digits, out, 0, 0);
        return hash;
    }
};