// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	
bool isValid(int i,int j,int N){
       return i>=0 && i<N && j>=0 && j<N;
   }
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    int x=KnightPos[0];
    int y=KnightPos[1];
    int t1=TargetPos[0];
    int t2=TargetPos[1];
    x--;
    y--;
    t1--;
    t2--;
    bool visted[N][N]={false};
    visted[x][y]=true;
    queue<pair<int,int>>q;
    vector<pair<int,int>>vp={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    q.push({x,y});
    int c=0;
    while(!q.empty()){
        int s=q.size();
        while(s--){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if(a==t1 && b==t2){
                return c;
            }
            for(int i=0;i<8;i++){
                int dx=a+vp[i].first;
                int dy=b+vp[i].second;
                if(isValid(dx,dy,N) && visted[dx][dy]==false){
                    visted[dx][dy]=true;
                    q.push({dx,dy});
                }
            }
        }
        c++;
    }
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