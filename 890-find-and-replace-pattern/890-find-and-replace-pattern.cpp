class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char>hash;
        vector<string>s;
        
        unordered_map<char, int>hash2;
        
        for(int i=0; i<pattern.size(); i++){
            hash2[pattern[i]]++;
        }
        
        for(int i=0; i<words.size(); i++){
            if(pattern.size() != words[i].size()){
                continue;
            }
            bool flag = true;
            string tan = words[i];
            for(int j=0; j<tan.size(); j++){
                if(hash.count(pattern[j])){
                    // cout << hash[pattern[j]] << ", " << tan[j] << endl;
                    if(hash[pattern[j]] != tan[j]){
                        flag = false;
                    }
                }else{
                    hash[pattern[j]] = tan[j];
                }
            }
            unordered_map<char, int>hash1;
            bool flag2 = 1;
            for(int a=0; a<tan.size(); a++){
                hash1[tan[a]]++;
            }
            
            for(auto x : hash){
                char a = x.first;
                char b = x.second;
                cout << a << ", " << b <<",," << hash2[a] << ",  ," << hash1[b]<< endl;
                if(hash2[a]!=hash1[b]){
                    flag2 = false;
                }
            }
            cout << flag << "flag" << flag2 << ", " << endl;
            
            if(flag and flag2){
                s.push_back(tan);
            }
            hash.clear();
            flag = true;
            flag2 = true;
        }
        return s;
    }
};