class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count =0;
        for(int i=0; i<g.size(); i++){
            auto it = lower_bound(s.begin(), s.end(), g[i]) - s.begin();
            if(it != s.size()){
                count++;
                s.erase(s.begin()+it);
            }
        }
        
        return count;
    }
};