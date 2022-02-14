class Solution {
public:
    // int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for(int i=0;i<obstacles.size();i++) obs.insert(to_string(obstacles[i][0])+"#"+to_string(obstacles[i][1]));
        int res=0, dir=0, x=0, y=0;
        vector<vector<int>> ds={{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i=0;i<commands.size();i++) {
            if(commands[i]==-2) dir--;
            else if(commands[i]==-1) dir++;
            else {
                for(int j=0;j<commands[i];j++) {
                    string pos=to_string(x+ds[dir][0])+"#"+to_string(y+ds[dir][1]);
                    if(obs.find(pos)!=obs.end()) break;
                    x+=ds[dir][0], y+=ds[dir][1];
                }
                res=max(res, x*x+y*y);
            }
            if(dir==-1) dir=3;
            if(dir==4) dir=0;
        }
        return res;
    }
        // unordered_map<string, int>hash;
        // int n = obstacles.size();
        // int max_so_far = INT_MIN;
        // for(int i=0; i<n; i++){
        //     string s;
        //     s += to_string(obstacles[i][0]);
        //     s += "#";
        //     s += to_string(obstacles[i][1]);
        //     hash[s]++;
        // }
        // char curr_dirx = 'N';
        // int x = 0, y = 0;
        // for(int i=0; i<commands.size(); i++){
        //     if(commands[i]==-1){
        //         if(curr_dirx == 'N'){
        //             curr_dirx = 'E';
        //         }else if(curr_dirx == 'E'){
        //             curr_dirx = 'S';
        //         }else if(curr_dirx == 'S'){
        //             curr_dirx = 'W';
        //         }else if(curr_dirx == 'W'){
        //             curr_dirx = 'N';
        //         }
        //     }
        //     else if(commands[i]==-2){
        //         if(curr_dirx == 'N'){
        //             curr_dirx = 'W';
        //         }else if(curr_dirx == 'W'){
        //             curr_dirx = 'S';
        //         }else if(curr_dirx == 'S'){
        //             curr_dirx = 'E';
        //         }else if(curr_dirx == 'E'){
        //             curr_dirx = 'N';
        //         }
        //     }
        //     else{
        //         int dist = commands[i];
        //         if(curr_dirx == 'N'){
        //             for(int i=0; i<dist; i++){
        //                 string s;
        //                 s += to_string(x);
        //                 s += "#";
        //                 s += to_string(y+1);
        //                 if(hash.count(s)){
        //                     // y--;
        //                     break;
        //                 }else{
        //                     y++;
        //                 }
        //             }
        //         }
        //         else if(curr_dirx == 'E'){
        //             for(int i=0; i<dist; i++){
        //                 string s;
        //                 s += to_string(x+1);
        //                 s += "#";
        //                 s += to_string(y);
        //                 if(hash.count(s)){
        //                     // x--;
        //                     break;
        //                 }else{
        //                     x++;
        //                 }
        //             }
        //         }
        //         else if(curr_dirx == 'S'){
        //             for(int i=0; i<dist; i++){
        //                 string s;
        //                 s += to_string(x);
        //                 s += "#";
        //                 s += to_string(y-1);
        //                 if(hash.count(s)){
        //                     // y++;
        //                     break;
        //                 }else{
        //                     y--;
        //                 }
        //             }
        //         }
        //         else if(curr_dirx == 'W'){
        //             for(int i=0; i<dist; i++){
        //                 string s;
        //                 s += to_string(x-1);
        //                 s += "#";
        //                 s += to_string(y);
        //                 if(hash.count(s)){
        //                     // x++;
        //                     break;
        //                 }else{
        //                     x--;
        //                 }
        //             }
        //         }
        //     }
        //     cout << x << ", " << y << endl;
        //     max_so_far = max(max_so_far,  x*x + y*y);
        // }
        // return max_so_far;
    // }
};