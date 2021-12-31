class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string, int>hash;
        int n = word.length();
        string s="";
        for(int i=0; i<n; i++){
            if(word[i]>='0' and word[i]<='9'){
                s += word[i];
            }else{
                if(s.size()){
                    
                    int j = 0;
                    while(s[j]=='0'){
                        j++;
                    }
                    s = s.substr(j);
                    hash[s]++;
                }
                s = "";
            }
        }
        if(s.size()){
            int j = 0;
            while(s[j]=='0'){
                j++;
            }
            s = s.substr(j);
            hash[s]++;
        }
        int count = 0;
        for(auto x : hash){
            cout << x.first << endl;
            if(x.first[0] != '0'){
                count++;
            }
        }
        return count;
    }
};