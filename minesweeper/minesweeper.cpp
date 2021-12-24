class Solution {
public:
    
    int m,n;
    
    vector<pair<int,int>> v={{1,1},{1,0} ,{1,-1} ,{0,1} ,{0,-1} ,{-1,1} ,{-1,0} ,{-1,-1} } ;
    
    void reveal(vector<vector<char>>& board,int i,int j){
     
          if(i<0||i>=m||j<0||j>=n||board[i][j]!='E') return ;
         
          int ans=0;
         for(auto p:v){
             int a=i+p.first;
             int b=j+p.second;
              if(a<0||a>=m||b<0||b>=n) continue;
             
             if(board[a][b]=='M') ans++;
          }
        
        if(ans>0){
             board[i][j]=ans+'0';
            return ;
        }
        
  
         board[i][j]='B';
        
         for(auto p:v){
             int a=i+p.first;
             int b=j+p.second;
               reveal(board,a,b);
           }
       
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        // start position contains mine then no further revealing
        if(board[click[0]][click[1]]=='M') {
            
            board[click[0]][click[1]]='X';
            return board;
        }
        
        m=board.size();
        n=board[0].size();
        
        // start revealing with click = [clickr, clickc]
         reveal( board,click[0],click[1]);
    
        return board;
    
    }
};