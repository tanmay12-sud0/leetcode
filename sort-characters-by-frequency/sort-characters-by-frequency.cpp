bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    if(a.second == b.second){
        return a<b;
    }
        return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int>hash;
        int len = s.length();
        for(int i=0; i<len; i++){
            hash[s[i]]++;
        }
        vector<pair<char, int> > A;
        
        for (auto& it : hash) {
            A.push_back(it);
        }
        
        sort(A.begin(), A.end(), cmp);
        
        string ss;
        
        for(auto x : A){
            while(x.second !=0){
                ss += x.first;
                x.second--;
            }
        }
        return ss;
           
    }
};