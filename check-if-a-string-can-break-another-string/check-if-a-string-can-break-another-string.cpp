class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.size();
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]>=s2[i]){
                count1++;
            }
            if(s1[i]<=s2[i]){
                count2++;
            }
        }
        if(count1==n or count2==n){
            return true;
        }
        return false;
    }
};