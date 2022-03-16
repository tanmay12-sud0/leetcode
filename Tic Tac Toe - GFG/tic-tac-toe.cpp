// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isValid(char board[9]){
        bool oo=false, xx=true;
        int cnto = 0, cntx = 0;
        for(int i=0; i<9; i++){
            if(board[i] == 'O')
                cnto += 1;
            else 
                cntx +=1;
        }
       int win[8][3]= {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
       for(int i=0; i<8; i++){
           if(board[win[i][0]]=='O' && board[win[i][1]]=='O' && board[win[i][2]]=='O')
               oo=true;
       }
       if(oo == true || cntx-cnto != 1)
           return false;
       return true;
    }
    
    
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        char board[9];
        for (int i = 0; i < 9; i++) {
            cin >> board[i];
        }
        Solution ob;
        auto ans = ob.isValid(board);
        cout << (ans ? "Valid\n" : "Invalid\n");
    }
    return 0;
}  // } Driver Code Ends