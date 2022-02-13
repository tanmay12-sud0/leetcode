class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>hash;
        for(int i=0; i<s.length(); i++){
            if(s[i] == c){
                hash.push_back(i);
            }
        }
        for(auto x : hash){
            cout << x << ", ";
        }
        cout << endl;
        vector<int>umap;
        int mina = INT_MAX;
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<hash.size(); j++){
                mina = min(mina, abs(hash[j]-i));
            }
            umap.push_back(mina);
            mina = INT_MAX;
        }
        return umap;
    }
};