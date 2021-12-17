class Solution {
public:
    int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
	// check if cordinates are outside the board
    bool checkBoundries (int nextr, int nextc)
    {
        if (nextr < 0 || nextr >= 8 || nextc < 0 || nextc >= 8)
            return false;
        
        return true;
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        char oppositeColor = (color == 'W') ? 'B' : 'W';
        
        for (int i = 0; i < 8; i++)
        {
            int nextr = rMove + dr[i];
            int nextc = cMove + dc[i];
            
            if (checkBoundries (nextr, nextc))
                if (board[nextr][nextc] == oppositeColor)
                {
					// go as far as middle elements are
                    while (board[nextr][nextc] == oppositeColor)
                    {
                        nextr += dr[i];
                        nextc += dc[i];      
                        if (!checkBoundries (nextr, nextc)) 
                            break;
                    }
					
					// at the end check if ending point is valid
                    if (checkBoundries (nextr, nextc))
                        if (board[nextr][nextc] == color)
                            return true;
                }
        }
		
		// if none of 8 can be valid
        return false;        
    }
};






// class Solution {
// public:
//     bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
//         int n = board.size();
//         int m = board[0].size();
        
//         int i = rMove;
//         int j = cMove;
        
//         for(int x = cMove+1; x<m; x++){
//             if(board[rMove][x] == 'W'){
//                 if(x-cMove >= 3){
//                     cout << "hello";
//                     return true;
//                 }else{
//                     break;
//                 }
//             }
//         }
        
//         for(int x = cMove-1; x>=0; x--){
//             if(board[rMove][x] == 'W'){
//                 if(abs(x-cMove) >= 3){
//                                         cout << "hello1";

//                     return true;
//                 }else{
//                     break;
//                 }
//             }
//         }
        
//         for(int x = rMove-1; x>=0; x--){
//             if(board[x][cMove] == 'W'){
//                 if(abs(x-rMove) >= 3){
//                                         cout << "hello2";

//                     return true;
//                 }else{
//                     break;
//                 }
//             }
//         }
        
        
//         for(int x = rMove+1; x<n; x++){
//             if(board[x][cMove] == 'W'){
//                 if(abs(x-rMove) >= 3){
//                                         cout << "hello3";

//                     return true;
//                 }else{
//                     break;
//                 }
//             }
//         }
        
//         int l = cMove+1;
//         for(int x = rMove+1; x<min(n,m); x++){
//             if(board[x][l++] == 'W'){
//                 if()
//             }
//         }
        
        
        
        
//       return false;  
        
        
//     }
// };