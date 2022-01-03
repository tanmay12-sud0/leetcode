class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& start, string s) {
        int size=s.size();
        vector<int>ans(size,0);
		// for finding answer iterate over all points one by one
        for(int i=0;i<size;i++)
           ans[i]= findSteps(n,s,start[0],start[1],i);
        return ans; 
    }
	// check how many steps you can go
    int findSteps(int &n,string &s,int row,int col,int pos){
       int ans=0;
        for(int i=pos;i<s.size();i++){
            if(s[i]=='L')
                col--;
            else if(s[i]=='R')
                col++;
            else if(s[i]=='U')
                row--;
            else
                row++;
				// if it is true then this move is invalid,return ans
            if(row<0 || col<0 || row>=n || col>=n)
                return ans;
				// else go to next move.
            ans++;
        }
        return ans;
    }
};























// recursive approch TLE

// class Solution {
// public:
    
    
//     void check(int n, int i, int j, string s, int index, int &count){
//         if(s[index] == 'L' and j-1 >= 0){
//             count++;
//             check(n, i, j-1, s, index+1, count);
//         }
//         else if(s[index] == 'R' and j+1<n){
//             count++;
//             check(n, i, j+1, s, index+1, count);
//         }
//         else if(s[index] == 'U' and i-1>=0){
//             count++;
//             check(n, i-1, j, s, index+1, count);
//         }
//         else if(s[index] == 'D' and i+1<n){
//             count++;
//             check(n, i+1, j, s, index+1, count);
//         }
//         return;
// }
    
    
    
//     vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
//         vector<int>umap;
//         for(int i=0; i<s.length(); i++){
//             int count = 0;
//             cout << s.substr(i) << endl;
//             check(n, startPos[0], startPos[1], s.substr(i), 0, count);
//             umap.push_back(count);
//         }
//         return umap;
//     }
// };