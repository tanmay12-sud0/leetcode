class Solution {
public:
    
    bool verifyOrigin(int x, int y){
        if(x==0 and y==0){
            return true;
        }
        return false;
    }
    
    
    bool isRobotBounded(string instructions) {
        int n = instructions.length();
        if(n==0){
            return false;
        }
        int x =0, y =0;
        char curr_dirx = 'N';
        for(int i=0; i<n; i++){
            if(instructions[i] == 'G'){
                cout << curr_dirx << endl; 
                if(curr_dirx == 'N'){
                    y++;
                }
                if(curr_dirx == 'S'){
                    y--;
                }
                if(curr_dirx == 'E'){
                    x++;
                }
                if(curr_dirx == 'W'){
                    x--;
                }
            }else{
                char incoming = instructions[i];
                if(curr_dirx == 'N'){
                    curr_dirx = incoming=='L' ? 'W' : 'E';
                }
                else if(curr_dirx == 'W'){
                    curr_dirx = incoming=='L' ? 'S' : 'N';
                }
                else if(curr_dirx == 'S'){
                    curr_dirx = incoming=='L' ? 'E' : 'W';
                }
                else if(curr_dirx == 'E'){
                    curr_dirx = incoming=='L' ? 'N' : 'S';
                }
            }
        }
        // cout << curr_dirx << ", " << ", " << x << ", " << y << endl;
        if(verifyOrigin(x, y) or curr_dirx!='N'){
            return true;
        }
        return false;
    }
};