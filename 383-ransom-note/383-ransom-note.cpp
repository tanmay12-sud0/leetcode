class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>hash;
        for(int i=0; i<magazine.size(); i++){
            hash[magazine[i]]++;
        }
        for(auto x : hash){
            cout << x.first << ", " << x.second << endl;
        }
        for(int i=0; i<ransomNote.size(); i++){
            cout << ransomNote[i] << endl;
            if(hash.count(ransomNote[i]) and hash[ransomNote[i]]!=0){
                hash[ransomNote[i]]--;
            }else{
                return false;
            }
        }
        return true;
    }
};