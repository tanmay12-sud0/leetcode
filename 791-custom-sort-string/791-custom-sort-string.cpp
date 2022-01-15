class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>hash;
        for(int i=0; i<s.length(); i++){
            hash[s[i]]++;
        }
        string p;
        for(int i=0; i<order.length(); i++){
            if(hash.count(order[i])){
                while(hash[order[i]]!=0){
                    p += order[i];
                    hash[order[i]]--;
                } 
            }
        }
        for(auto x : hash){
            while(x.second>0){
                p += x.first;
                x.second--;
            }
        }

        return p;
    }
};