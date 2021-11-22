class Solution {
public:
    string reversePrefix(string word, char ch) {
        int len = word.length();
        int index = -1;
        for(int i=0; i<len; i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }
        if(index == -1){
            return word;
        }
        int start = 0;
        int end = index;
        while(start < end){
            swap(word[start], word[end]);
            start++,end--;
        }
        return word;
    }
};