class Solution {
public:
    bool winnerOfGame(string colors) {
        int moveA = 0;
        int moveB = 0;
        int n = colors.size();
        for(int i=1; i<n-1; i++){
            if(colors[i] == 'A' and colors[i-1]=='A' and colors[i+1] == 'A'){
                moveA++;
            }
            if(colors[i] == 'B' and colors[i-1]=='B' and colors[i+1] == 'B'){
                moveB++;
            }
        }
        if(moveA > moveB){
            return true;
        }
        return false;
    }
};