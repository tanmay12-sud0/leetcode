// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int tx = TargetPos[0];
	    int ty = TargetPos[1];
	    int ii = KnightPos[0];
	    int jj = KnightPos[1];
	    queue<pair<int, int>>q;
	    int vis[N+1][N+1] = {0};
	    int dis[N+1][N+1] = {0};
	    q.push({ii, jj});
	    vis[ii][jj] = true;
	    dis[ii][jj] = 0;
	   int dx[] = {-2,-2,-1,-1,1,1,2,2};
       int dy[] = {-1,1,-2,2,-2,2,-1,1};
       
       while(!q.empty()){
           int currX = q.front().first;
           int currY = q.front().second;
           q.pop();
           for(int p=0; p<8; p++){
               int xx = currX + dx[p];
               int yy = currY + dy[p];
               if(xx>0 and yy>0 and xx<=N and yy<=N and !vis[xx][yy]){
                   vis[xx][yy] = true;
                   dis[xx][yy] = dis[currX][currY] + 1;
                   q.push({xx, yy});
               }
           }
       }
       return dis[tx][ty];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends