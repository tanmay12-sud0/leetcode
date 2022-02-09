class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int value = 0;
        long long int key = 1;
        for(int i=columnTitle.size()-1; i>=0; i--){
            int j = 1;
            while('A'+j-1 != columnTitle[i]){
                j++;
            }
            value += key*j;
            key = key*26;
        }
        return value;
    }
};