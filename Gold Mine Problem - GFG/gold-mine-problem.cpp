// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        if(n==1 and m!=1)
        {
            int sum=0;
            for(int i=m-1;i>=0;i--)
            {
                sum+=M[0][i];
            }
            M[0][0] = sum;
            
        }
        else{
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                M[j][i] = M[j][i]+max({M[j][i+1],M[j+1][i+1]});
                }
                else if(j!=0 and j!=n-1)
                {
                    M[j][i]=  M[j][i]+max({M[j-1][i+1],M[j][i+1],M[j+1][i+1]});
                }
                
                else if(j==n-1)
                {
                    M[j][i] =  M[j][i]+max({M[j][i+1],M[j-1][i+1]});
                }
            }
        }
        }
        
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            if(maxx<M[i][0])
            {
                maxx = M[i][0];
            }
        }
        
        return maxx;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends