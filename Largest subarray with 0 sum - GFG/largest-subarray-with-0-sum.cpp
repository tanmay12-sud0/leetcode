// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int>hash;
        for(int i=1; i<n; i++){
            A[i] = A[i] + A[i-1];
        }
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(A[i] == 0){
                maxLen = max(maxLen, i+1);
            }
            else if(hash.count(A[i])){
                maxLen = max(maxLen, i-hash[A[i]]);
            }
            else{
                hash[A[i]] = i;
            }
        }
        return maxLen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends