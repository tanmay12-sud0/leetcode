// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>>hash;
        int indexBuy = -1;
        int indexSell = -1;
        int buy = 0;
        int sell = 0;
        int profit = 0;
        if(A[0] < A[1]){
            buy = 1;
            indexBuy = 0;
        }
        for(int i=1; i<n-1; i++){
            if(buy == 1){
                if(A[i] > A[i+1]){
                    sell = 1;
                    profit += A[i] - (A[indexBuy]);
                    buy = 0;
                    hash.push_back({indexBuy, i});
                }
            }else{
                if(A[i] < A[i+1]){
                    buy = 1;
                    sell = 0;
                    indexBuy = i;
                }
            }
        }
        if(buy == 1){
            if(A[indexBuy] < A[n-1]){
                hash.push_back({indexBuy, n-1});
            }
        }
        return hash;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends