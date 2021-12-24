class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3,vector<char>(3));
        char val = 'x';
            
        //fill the grid
        for (auto a : moves){
        grid[a[0]][a[1]] = val;
        if (val == 'x')val ='o';
            else val = 'x';
        }
        
        //if A win or if B win
        for (int i = 0; i < 3; i++){
            //check row
            if (grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x')return "A";
            if (grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o')return "B";

            //check columns
            if (grid[0][i] == 'x' && grid[1][i] == 'x' && grid[2][i] == 'x')return "A";
            if (grid[0][i] == 'o' && grid[1][i] == 'o' && grid[2][i] == 'o')return "B";
        }
        
        //check diagonal 
        if (grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x')return "A";
        if (grid[0][2] == 'x' && grid[1][1] == 'x' && grid[2][0] == 'x')return "A";
        if (grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o')return "B";
        if (grid[0][2] == 'o' && grid[1][1] == 'o' && grid[2][0] == 'o')return "B";

        
        //if it is Pending
        if (moves.size() < 9)return "Pending";
        
        
        //if it's Draw
        return "Draw";      
    }
};
























// class Solution {
// public:
//     string tictactoe(vector<vector<int>>& moves) {
//         unordered_map<string, int>hash1;
//         unordered_map<string, int>hash2;
//         for(int i=0; i<moves.size(); i++){
//             if(i%2==0){
//                 string s;
//                 s += to_string(moves[i][0]);
//                 s += to_string(moves[i][1]);
//                 hash1[s]++;
//             }else{
//                 string s;
//                 s += to_string(moves[i][0]);
//                 s += to_string(moves[i][1]);
//                 hash2[s]++;
//             }
//         }
//         /// a wins
//         set<int>s1;
//         set<int>s2;
//         set<int>s3;
//         set<int>s4;
//         for(auto it=hash1.begin(); it!=hash1.end(); it++){
//             string s = it->first;
//             s1.insert((s[0]-'0'));
//             s2.insert((s[1]-'0'));
//             s3.insert((s[0]-'0') + (s[1]-'0'));
//             s4.insert((s[0]-'0') - (s[1]-'0'));
//         }
//         if(s1.size()== 1 or s2.size() == 1 or s3.size()==1 or s4.size()==1){
//             return "A";
//         }
//         /// b wins
//         set<int>s11;
//         set<int>s22;
//         set<int>s33;
//         set<int>s44;
//         for(auto it=hash2.begin(); it!=hash2.end(); it++){
//             string s = it->first;
//             s11.insert((s[0]-'0'));
//             s22.insert((s[1]-'0'));
//             s33.insert((s[0]-'0') + (s[1]-'0'));
//             s44.insert((s[0]-'0') - (s[1]-'0'));
//         }
//         if(s11.size()== 1 or s22.size() == 1 or s33.size()==1 or s44.size()==1){
//             return "B";
//         }
//         if(9 == moves.size()){
//             return "Draw";
//         }
//         return "Pending";
//     }
// };