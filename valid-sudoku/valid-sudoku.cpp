class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        // check each row
        for(int i=0; i<9; i++){
            set<int>hash;
            for(int j=0; j<9; j++){
                if(hash.count(board[i][j]-'0')){
                    return false;
                }else if(board[i][j]!='.'){
                    hash.insert(board[i][j]-'0');
                }
            }
            hash.clear();
        }
        // check each col
        for(int i=0; i<9; i++){
            set<int>hash;
            for(int j=0; j<9; j++){
                if(hash.count(board[j][i]-'0')){
                    return false;
                }else if(board[j][i]!='.'){
                    hash.insert(board[j][i]-'0');
                }
            }
            hash.clear();
        }
        // check each box
        for(int i=0; i<9; i+=3){
            
            for(int j=0; j<9; j+=3){
                set<int>hash;
                for(int ll=i; ll<i+3; ll++){
                    for(int pp=j; pp<j+3; pp++){
                        if(hash.count(board[ll][pp]-'0')){
                            return false;
                        }else if(board[ll][pp]!='.'){
                            hash.insert(board[ll][pp]-'0');
                        }
                    }
                }
                hash.clear();
            }
            
        }
        return true;
    }
};














// int row = board.size();
//         int col = board[0].size();
//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(board[i][j]!='.'){
//                     if(!checkRow(board, i, j, row, col) or !checkCol(board, i, j, row, col) or !checkBox(board, i, j, row, col)){
                    
//                     return false;
//                     }
//                 }
//             }
//         }
//         return true;










// bool checkRow(vector<vector<char>>& board, int i, int j,int row, int col){
//         unordered_set<int>hash;
//         for(int i=0; i<row; i++){
//             if(hash.count(board[i][j]-'0')){
//                 return false;
//             }else if(board[i][j]!='.'){
//                 hash.insert(board[i][j]-'0');
//             }
//         }
//         return true;
//     }
    
//     bool checkCol(vector<vector<char>>& board, int i, int j,int row, int col){
//         unordered_set<int>hash;
//         for(int i=0; i<col; i++){
//             if(hash.count(board[j][i]-'0')){
//                 return false;
//             }else{
//                  if(board[i][j]!='.'){
//                     hash.insert(board[i][j]-'0');
//                 }
//             }
//         }
//         for(auto x : hash){
//             cout << x <<", ";
//         }
//         cout << endl;
//         return true;
//     }
    
//     bool checkBox(vector<vector<char>>& board, int i, int j, int row, int col){
//         unordered_set<int>hash;
//         int x = (i/3)*3;
//         int y = (j/3)*3;
//         for(int i=x; i<x+3; i++){
//             for(int j=y; j<y+3; j++){
//                 if(hash.count(board[i][j]-'0')){
//                     return false;
//                 }else{
//                      if(board[i][j]!='.'){
//                     hash.insert(board[i][j]-'0');
//                     }
//                 }
//             }
//         }
       
//         return true;
//     }
    
    