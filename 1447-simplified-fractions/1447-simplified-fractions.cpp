class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>s;
        set<float>ss;
        for(int i=1; i<n; i++){
            for(int j=2; j<=n; j++){
                if(i%j!=0){
                    float xx = float(i)/float(j);
                    cout << xx << endl;
                    if(!ss.count(xx) and i/j<1){
                        string a = to_string(i);
                        a += '/';
                        a += to_string(j);
                        s.push_back(a);
                        ss.insert(xx);
                    }
                }
            }
        }
        return s;
    }
};