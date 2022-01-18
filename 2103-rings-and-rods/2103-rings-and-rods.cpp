class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length();
        unordered_map<int, set<char>>hash;
        for(int i=0; i<n; i+=2){
            char s = rings[i];
            int a = rings[i+1]-'0';
            hash[a].insert(s);
        }
        int cnt = 0;
        for(auto x : hash){
            if(x.second.size()==3){
                cnt++;
            }
        }
        return cnt;
    }
};