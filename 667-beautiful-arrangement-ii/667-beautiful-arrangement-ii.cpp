class Solution {
public:
    vector<int> constructArray(int n, int k) {
        set<int>s;
        vector<int>hash;
        for(int i=1; i<=n; i++){
            if(k>0 and !s.count(i)){
                hash.push_back(i);
                s.insert(i);
                k--;
            }
            cout << k << endl;
            if(k>0 and !s.count(n-i+1)){
                hash.push_back(n-i+1);
                k--;
                s.insert(n-i+1);
            }
        }
        int x = hash.back();
        while(x < n){
            if(!s.count(x)){
                hash.push_back(x);
                s.insert(x);
            }
            x++;
        }
        while(x > 0){
            if(!s.count(x)){
                hash.push_back(x);
                s.insert(x);
            }
            x--;
        }
        return hash;
    }
};