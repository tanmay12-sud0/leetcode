class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.length();
        int start = 0;
        int end = len-1;
        while(start < end){
            while(!((s[start]>='a' and s[start]<='z') or (s[start]>='A' and s[start]<='Z'))){
               if(start < end){
                   start++; 
               }else{
                   break;
               }
            }
            while(!((s[end]>='a' and s[end]<='z') or (s[end]>='A' and s[end]<='Z'))){
               if(start < end){
                   end--;
               }else{
                   break;
               } 
            }
            swap(s[start], s[end]);
            start++,end--;
        }
        return s;
        
    }
};