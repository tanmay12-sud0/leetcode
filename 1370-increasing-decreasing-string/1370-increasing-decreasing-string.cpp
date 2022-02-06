class Solution {
public:
    string sortString(string s) {
        map<char, int>hash;
        for(int i=0; i<s.length(); i++){
            hash[s[i]]++;
        }
        string ss;
        while(ss.length() != s.length()){
            for(int i=0; i<26; i++){
                if(hash.count('a'+i) and hash['a'+i]>0){
                    ss += 'a'+i;
                    hash['a'+i]--;
                }
            }
            for(int i=25; i>=0; i--){
                if(hash.count('a'+i) and hash['a'+i]>0){
                    ss += 'a'+i;
                    hash['a'+i]--;
                }
            }
        }
        return ss;
    }
};


// for(auto it = hash.begin(); it!= hash.end(); it++){
//                 ss += it->first;
//                 hash[it->first]--;
//                 if(hash[it->first] == 0){
//                     hash.erase(it->first);
//                 }
//             }
//             for(auto it = hash.rbegin(); it!= hash.rend(); it++){
//                 ss += it->first;
//                 hash[it->first]--;
//                 if(hash[it->first] == 0){
//                     hash.erase(it->first);
//                 }
//             }