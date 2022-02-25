class Solution {
public:
    char slowestKey(vector<int>& release, string key) {
        char s = 'a';
        int time = 0;
        time = release[0];
        s = key[0];
        for(int i=1; i<release.size(); i++){
            int diff = release[i] - release[i-1];
            if(diff == time){
                if(key[i] > s){
                    s = key[i];
                }
            }
            if(diff > time){
                time = diff;
                s = key[i];
            }
        }
        return s;
    }
};