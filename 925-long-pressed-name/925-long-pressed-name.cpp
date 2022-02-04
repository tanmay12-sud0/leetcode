class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameLen = name.length();
        int typedLen = typed.length();
        if(nameLen > typedLen){
            return false;
        }
        int j=0;
        for(int i=0; i<typedLen;){
            if(typed[i] == name[j]){
                i++,j++;
            }else if(i!=0 and typed[i] == name[j-1]){
                i++;
            }else{
                return false;
            }
            
        }
        if(j==nameLen){
            return true;
        }
        return false;
    }
};