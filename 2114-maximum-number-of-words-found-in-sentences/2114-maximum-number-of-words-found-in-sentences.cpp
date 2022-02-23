class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int max_so_far = INT_MIN;
        for(int i=0; i<n; i++){
            string s = sentences[i];
            int cnt = 0;
            for(auto x : s){
                if(x == ' '){
                    cnt++;
                }
            }
            max_so_far = max(max_so_far, cnt);
        }
        return max_so_far+1;
    }
};