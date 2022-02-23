class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string s1,s2,s3;
        for(auto x : firstWord){
            int a = (x-'a');
            s1 += to_string(a);
        }
        for(auto x : secondWord){
            int a = (x-'a');
            s2 += to_string(a);
        }
        for(auto x : targetWord){
            int a = (x-'a');
            s3 += to_string(a);
        }
        cout << s1 << " " << s2 << " " << s3 << endl;
        if(stoi(s1) + stoi(s2) == stoi(s3)){
            return true;
        }
        return false;
    }
};